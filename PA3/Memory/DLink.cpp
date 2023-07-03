//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "DLink.h"

namespace Azul
{

	DLink &DLink::operator = (const DLink &)
	{
		this->Reset();
		return *this;
	}

	DLink::DLink()
	{
		this->Reset();
	}

	DLink::DLink(const DLink &)
	{
		this->Reset();
	}

	DLink::~DLink()
	{
		// do nothing
	}

	void DLink::Reset()
	{
		this->pNext = nullptr;
		this->pPrev = nullptr;
	}

}

// ---  End of File ---
