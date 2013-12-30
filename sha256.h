#pragma once

#include <string>
#include "Common.h"
#include "uint256_t.h"

namespace eth
{

class SHA256
{
protected:
	const static uint32_t sha256_k[];
	static const unsigned SHA224_256_BLOCK_SIZE = (512/8);
public:
	void init();
	void update(byte const* message, unsigned len);
	void final(byte* digest);
	static const unsigned int DIGEST_SIZE = ( 256 / 8);

protected:
	void transform(byte const* message, unsigned block_nb);
	unsigned m_tot_len;
	unsigned m_len;
	byte m_block[2*SHA224_256_BLOCK_SIZE];
	uint32_t m_h[8];
};

std::string sha256(std::string const& input, bool _hex);
uint256_t sha256(bytes const& input);

#define SHA2_SHFR(x, n)    (x >> n)
#define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define SHA2_ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z))
#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA256_F1(x) (SHA2_ROTR(x,  2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x, 22))
#define SHA256_F2(x) (SHA2_ROTR(x,  6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x, 25))
#define SHA256_F3(x) (SHA2_ROTR(x,  7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,  3))
#define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x, 10))
#define SHA2_UNPACK32(x, str)                 \
{                                             \
	*((str) + 3) = (uint8_t) ((x)      );       \
	*((str) + 2) = (uint8_t) ((x) >>  8);       \
	*((str) + 1) = (uint8_t) ((x) >> 16);       \
	*((str) + 0) = (uint8_t) ((x) >> 24);       \
}
#define SHA2_PACK32(str, x)                   \
{                                             \
	*(x) =   ((uint32_t) *((str) + 3)      )    \
		   | ((uint32_t) *((str) + 2) <<  8)    \
		   | ((uint32_t) *((str) + 1) << 16)    \
		   | ((uint32_t) *((str) + 0) << 24);   \
}

}


