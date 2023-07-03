//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef UNIT_TEST_CONFIGURATION_H
#define UNIT_TEST_CONFIGURATION_H

//--------------------------------------------------------------
// Make sure all are enabled for final submission...
//      I grade whatever is set in this file - Keenan
//--------------------------------------------------------------

//--------------------------------------------------------------
// TESTS below Mem::Align::Byte_4 is default...   - Test A
//       You can ignore alignment until you begin that section
//--------------------------------------------------------------

#define Version_verify                     true 

#define Initialize_MemorySystem	           true 

#define No_Initialize_MemorySystem         true	
#define No_Initialize_Destroy              true 

#define No_Initialize_HeapCreate           true
#define Initialize_HeapCreate              true 

#define No_Initialize_NullHeap_Destroy     true
#define No_Initialize_Heap_Destroy         true
										   
#define Initialize_NullHeap_Destroy        true
#define Initialize_WrongHeap_Destroy       true
#define Initialize_Heap_Destroy            true

#define AddOneHeap                         true
#define Add4Heaps                          true 

#define Add4Heaps_RemoveLastHeap           true 
#define Add4Heaps_RemoveMiddleHeap         true
#define Add4Heaps_RemoveFirstHeap          true 
#define Add4Heaps_RemoveAllHeaps           true 

#define No_Initialize_GetHeapByAddr        true 
#define Initialize_GetHeapByAddr_badPtr    true

#define allocate_from_heap                 true 
#define allocate_from_heapARRAY            true 
#define allocate_from_heapARRAY2           true 
#define allocate_from_heapARRAY3           true
#define allocate_5_from_heap               true 

#define test1_heapcCheck                   true
#define test1_heapcCheck2                  true
#define test1_heapcCheck3                  true

#define test1_trackCheck                   true 
#define test1_trackCheck2                  true 
#define test1_trackCheck3                  true
#define test1_trackCheck4                  true 

//--------------------------------------------------------------
// TESTS below Tracking to be working - Test A
//--------------------------------------------------------------

#define Add5Allocs_TrackingThroughHeap                       true 
#define Add4Allocs_RemoveLast_TrackingThroughHeap            true 
#define Add4Allocs_RemoveFirst_TrackingThroughHeap           true 
#define Add4Allocs_RemoveMiddle_TrackingThroughHeap          true 
#define Add4Allocs_RemoveAll_TrackingThroughHeap             true 

#define Add5Allocs_TrackingThroughHeap_Global                true 
#define Add4Allocs_RemoveLast_TrackingThroughHeap_Global     true 
#define Add4Allocs_RemoveFirst_TrackingThroughHeap_Global    true
#define Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global   true
#define Add4Allocs_RemoveAll_TrackingThroughHeap_Global      true

//--------------------------------------------------------------
// TESTS below Require Alignment to be working  - Test B
//--------------------------------------------------------------

#define align_4byte_check      true
#define align_8byte_check      true
#define align_16byte_check     true
#define align_32byte_check     true
#define align_64byte_check     true 
#define align_128byte_check    true 
#define align_256byte_check    true 

#define AlignCheck             true 
#define AlignCheck2            true 

//--------------------------------------------------------------
// TESTS below require Fixed heaps  - Test B
//--------------------------------------------------------------

#define fixed_check1           false
#define fixed_check2           false

#define fixed_overflow1        false
#define fixed_overflow2        false

#define Fixed_Tracking         false
#define Fixed2_Tracking        false

#endif

// --- End of File ---
