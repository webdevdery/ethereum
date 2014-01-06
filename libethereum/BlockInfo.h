/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Foobar is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file BlockInfo.h
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#pragma once

#include "Common.h"

namespace eth
{

struct BlockInfo
{
public:
	u256 hash;
	u256 parentHash;
	u256 sha256Uncles;
	u256 coinbaseAddress;
	u256 sha256Transactions;
	u256 difficulty;
	u256 timestamp;
	u256 nonce;
	u256 number;

	BlockInfo();

	explicit operator bool() { return number != Invalid256; }

	bool operator==(BlockInfo const& _cmp) const { return hash == _cmp.hash && parentHash == _cmp.parentHash && nonce == _cmp.nonce && number == _cmp.number; }

	void populate(bytesConstRef _block, u256 _number);
	void verify(bytesConstRef _block, u256 _number);
};

}


