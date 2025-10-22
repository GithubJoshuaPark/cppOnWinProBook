#include <iostream>
#include "utils.h"
#include <bitset> // for std::bitset
#include "bitManipulationEx.h"

using namespace std;

void bitManipulationEx(void) {
  printLine("bitManipulationEx Start");

  unsigned int x = 0b0010'1100; // 44
  cout << "초기값 x = " << x << " (binary: " << bitset<8>(x) << ")\n";

  // 비트 설정: set bit 0
  x |= (1u << 0);
  cout << "set bit 0 -> " << x << " (" << bitset<8>(x) << ")\n";

  // 비트 클리어: clear bit 3
  x &= ~(1u << 3);
  cout << "clear bit 3 -> " << x << " (" << bitset<8>(x) << ")\n";

  // 비트 토글: toggle bit 2
  x ^= (1u << 2);
  cout << "toggle bit 2 -> " << x << " (" << bitset<8>(x) << ")\n";

  // 비트 테스트: test bit 5
  bool bit5 = (x & (1u << 5)) != 0;
  cout << "bit 5 is " << (bit5 ? "1" : "0") << "\n";

  // 왼쪽/오른쪽 시프트
  unsigned int left = x << 1;
  unsigned int right = x >> 2;
  cout << "left shift <<1: " << left << " (" << bitset<8>(left) << ")\n";
  cout << "right shift >>2: " << right << " (" << bitset<8>(right) << ")\n";

  // 비트 개수 세기 (std::bitset 사용)
  cout << "set bits count: " << bitset<8>(x).count() << "\n";

  // 마스크 예: 플래그 정의
  constexpr unsigned FLAG_A = 1u << 0;
  constexpr unsigned FLAG_B = 1u << 1;
  unsigned flags = 0;
  flags |= FLAG_A;            // A 켜기
  flags |= FLAG_B;            // B 켜기
  flags &= ~FLAG_A;           // A 끄기
  cout << "flags = " << bitset<8>(flags) << "\n";


  cout << "flags = " << bitset<8>(flags) << "\n";

  // 추가 예제: 최하위 1비트 분리 및 제거
  {
    unsigned isolate = x & -x;               // 최하위 1비트만 남김
    unsigned cleared = x & (x - 1);          // 최하위 1비트 제거
    cout << "isolate lowest set bit -> " << bitset<8>(isolate) << "\n";
    cout << "after clearing lowest set bit -> " << bitset<8>(cleared) << "\n";
  }

  // 추가 예제: 2의 거듭제곱 검사
  auto isPowerOfTwo = [](unsigned v)->bool { return v && !(v & (v - 1)); };
  cout << "x is power of two? " << (isPowerOfTwo(x) ? "yes" : "no") << "\n";

  // 추가 예제: 8비트 단위 회전 (rotate left / right)
  auto rotl8 = [](unsigned v, int n)->unsigned {
    n &= 7;
    return ((v << n) | (v >> (8 - n))) & 0xFFu;
  };
  auto rotr8 = [](unsigned v, int n)->unsigned {
    n &= 7;
    return ((v >> n) | (v << (8 - n))) & 0xFFu;
  };
  cout << "rotl8(x,3): " << bitset<8>(rotl8(x,3)) << "\n";
  cout << "rotr8(x,2): " << bitset<8>(rotr8(x,2)) << "\n";

  // 추가 예제: 니블(nibble) 패킹/언패킹
  {
    unsigned hi = 0xA, lo = 0x5;
    unsigned packed = (hi << 4) | (lo & 0xF);
    cout << "packed nibbles (hex): 0x" << hex << packed << dec << " (" << bitset<8>(packed) << ")\n";
    cout << "unpacked hi=" << ((packed >> 4) & 0xF) << " lo=" << (packed & 0xF) << "\n";
  }

  // 추가 예제: 비트 개수 (popcount) — 컴파일러별 빌트인 사용 예
#if defined(__GNUG__) || defined(__clang__)
  cout << "popcount (builtin): " << __builtin_popcount(x) << "\n";
#elif defined(_MSC_VER)
  // MSVC에서는 <intrin.h>의 __popcnt(unsigned) 사용 가능 (링크/설정에 따라 다름)
  cout << "popcount: (platform specific, use std::bitset or <bit> in C++20)\n";
#else
  cout << "popcount: use std::bitset or C++20 std::popcount\n";
#endif

  printLine("bitManipulationEx End");
}