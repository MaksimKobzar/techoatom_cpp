#include "stdafx.h"

#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>

std::ifstream fileA("A.txt");
std::ofstream fileB("B.txt");
//std::string ordinary("and $0, $1, $2"), immediate("andi $0, $1, 65535");

using EncodingFunctionSignature = std::function<uint32_t(uint32_t, uint32_t, uint32_t)>;
std::unordered_map<std::string, EncodingFunctionSignature>	encodingFunctions;
std::unordered_map<std::string, uint32_t>					cmd_base;

auto enc_reg = [](uint32_t d, uint32_t s, uint32_t t) -> uint32_t {
	return ((s & 0x1f) << 21) | ((t & 0x1f) << 16) | (d & 0x1f << 11);
};

auto enc_imm = [](uint32_t t, uint32_t s, uint32_t imm_value) -> uint32_t {
	return ((s & 0x1f) << 21) | ((t & 0x1f) << 16) | (imm_value & 0xffff << 0);
};


bool init()
{
	cmd_base["and"] = 0x24;			encodingFunctions["and"] = enc_reg;
	cmd_base["andi"] = 0x30000000;		encodingFunctions["andi"] = enc_imm;
	return true;
}

uint32_t decode_arg(const std::string &args)
{
	size_t shift = args.find_first_of('$')+1;
	std::string arg_cut = args.substr(shift);
	return atoi(arg_cut.c_str());
}

uint32_t encode(const std::string &cmd)
{
	std::vector<std::string>	cmd_args;
	std::string					cmd_name = cmd.substr(0, cmd.find_first_of(' '));

	auto arg_start = cmd.find(' ') + 1, arg_length = cmd.find(',') - arg_start;
	while (arg_start > 0)
	{
		cmd_args.push_back(cmd.substr(arg_start, arg_length));
		arg_start = cmd.find(' ', arg_start) + 1;
		arg_length = cmd.find(',', arg_start) - arg_start;
	}

	if (cmd_args.size() == 1)
		return cmd_base[cmd_name] | encodingFunctions[cmd_name](decode_arg(cmd_args[0]), 0, 0);
	else if (cmd_args.size() == 2)
		return cmd_base[cmd_name] | encodingFunctions[cmd_name](decode_arg(cmd_args[0]), decode_arg(cmd_args[1]), 0);
	else if (cmd_args.size() == 3)
		return cmd_base[cmd_name] | encodingFunctions[cmd_name](decode_arg(cmd_args[0]), decode_arg(cmd_args[1]), decode_arg(cmd_args[2]));
	else throw std::runtime_error("given command is invalid");
}

int main()
{
	static bool initFlag = init();
	while (!fileA.eof()) {
		std::string str;
		std::getline(fileA, str);
		fileB << encode(str) << std::endl;
	}
	return 0;
}