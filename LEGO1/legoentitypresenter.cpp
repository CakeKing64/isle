#include "legoentitypresenter.h"

#include "legoomni.h"
#include "legovideomanager.h"

DECOMP_SIZE_ASSERT(LegoEntityPresenter, 0x50);

// OFFSET: LEGO1 0x10053440
LegoEntityPresenter::LegoEntityPresenter()
{
	Init();
}

// OFFSET: LEGO1 0x100535c0
void LegoEntityPresenter::Init()
{
	m_unk4c = 0;
}

// OFFSET: LEGO1 0x100535d0
LegoEntityPresenter::~LegoEntityPresenter()
{
	Destroy(TRUE);
}

// OFFSET: LEGO1 0x10053630
undefined4 LegoEntityPresenter::vtable6c(undefined4 p_unknown)
{
	m_unk4c = p_unknown;
	return 0;
}

// OFFSET: LEGO1 0x10053640
void LegoEntityPresenter::Destroy(MxBool p_fromDestructor)
{
	if (VideoManager()) {
		VideoManager()->RemovePresenter(*this);
	}

	Init();
}

// OFFSET: LEGO1 0x10053670
void LegoEntityPresenter::Destroy()
{
	Destroy(FALSE);
}
