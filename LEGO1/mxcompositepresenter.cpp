#include "mxcompositepresenter.h"

#include "decomp.h"
#include "mxnotificationmanager.h"

DECOMP_SIZE_ASSERT(MxCompositePresenter, 0x4c);

// OFFSET: LEGO1 0x100b60b0
MxCompositePresenter::MxCompositePresenter()
{
	NotificationManager()->Register(this);
}

// OFFSET: LEGO1 0x100b6390
MxCompositePresenter::~MxCompositePresenter()
{
	NotificationManager()->Unregister(this);
}

// OFFSET: LEGO1 0x100b67f0 STUB
void MxCompositePresenter::VTable0x58()
{
	// TODO
}

// OFFSET: LEGO1 0x100b69b0 STUB
void MxCompositePresenter::VTable0x5c()
{
	// TODO
}

// OFFSET: LEGO1 0x100b6b40 STUB
void MxCompositePresenter::VTable0x60()
{
	// TODO
}

// OFFSET: LEGO1 0x1000caf0 STUB
void MxCompositePresenter::VTable0x64()
{
	// TODO
}
