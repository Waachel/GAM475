//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef DLINK_H
#define DLINK_H

namespace Azul
{
	class DLink
	{
	public:
		// Big Four
		DLink();
		DLink(const DLink &);
		DLink &operator = (const DLink &);
		~DLink();

		void Reset();

	public:
		// data:------------------------
		DLink *pNext;
		DLink *pPrev;
	};

}

#endif

// ---  End of File ---------------
