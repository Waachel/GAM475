//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MemEngine.h"
#include "Dog.h"

using namespace Azul;

//--------------------------------------------------------------------------
// MACROS Test
//--------------------------------------------------------------------------

#define TEST_4_BYTE(ptr)      ( ((size_t)ptr & 0x3) == 0 )
#define TEST_8_BYTE(ptr)      ( ((size_t)ptr & 0x7) == 0 )
#define TEST_16_BYTE(ptr)     ( ((size_t)ptr & 0xF) == 0 )
#define TEST_32_BYTE(ptr)     ( ((size_t)ptr & 0x1F) == 0 )
#define TEST_64_BYTE(ptr)     ( ((size_t)ptr & 0x3F) == 0 )
#define TEST_128_BYTE(ptr)    ( ((size_t)ptr & 0x7F) == 0 )
#define TEST_256_BYTE(ptr)    ( ((size_t)ptr & 0xFF) == 0 )

//---------------------------------------------------------------------------
// Test Files:
// Single step, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(align_16byte_check, TestConfig::VERSION_CHECK)
{
#if align_16byte_check

	// Initialize the memory system
	Mem::Create();

	// create heap
	Mem::Code  memResult;
	Heap *heap_A;
	memResult = Mem::NormalHeap(heap_A, 100 * 1024, "HEAP_A");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::NORMAL);

	Dog *p0 = new(heap_A, Mem::Align::Byte_16, __FILE__, __LINE__) Dog();
	Dog *p1 = new(heap_A, Mem::Align::Byte_16, __FILE__, __LINE__) Dog();
	Dog *p2 = new(heap_A, Mem::Align::Byte_16, __FILE__, __LINE__) Dog();
	Dog *p3 = new(heap_A, Mem::Align::Byte_16, __FILE__, __LINE__) Dog();
	Dog *p4 = new(heap_A, Mem::Align::Byte_16, __FILE__, __LINE__) Dog();
	Dog *p5 = new(heap_A, Mem::Align::Byte_16, __FILE__, __LINE__) Dog();

	CHECK(p0 != nullptr);
	CHECK(p1 != nullptr);
	CHECK(p2 != nullptr);
	CHECK(p3 != nullptr);
	CHECK(p4 != nullptr);
	CHECK(p5 != nullptr);

	CHECK(TEST_16_BYTE(p0));
	CHECK(TEST_16_BYTE(p1));
	CHECK(TEST_16_BYTE(p2));
	CHECK(TEST_16_BYTE(p3));
	CHECK(TEST_16_BYTE(p4));
	CHECK(TEST_16_BYTE(p5));

	delete p0;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
