#include "mxsoundpresenter.h"

#include "decomp.h"
#include "mxsoundmanager.h"

DECOMP_SIZE_ASSERT(MxSoundPresenter, 0x54)

// OFFSET: LEGO1 0x1000d430
MxSoundPresenter::~MxSoundPresenter()
{
	Destroy(TRUE);
}

// OFFSET: LEGO1 0x100b1a50
void MxSoundPresenter::Destroy(MxBool p_fromDestructor)
{
	if (MSoundManager())
		MSoundManager()->RemovePresenter(*this);

	this->m_criticalSection.Enter();
	MxMediaPresenter::Init();
	this->m_criticalSection.Leave();

	if (!p_fromDestructor)
		MxMediaPresenter::Destroy(FALSE);
}

// OFFSET: LEGO1 0x100b1aa0
MxResult MxSoundPresenter::AddToManager()
{
	MxResult ret = FAILURE;

	if (MSoundManager()) {
		ret = SUCCESS;
		MSoundManager()->AddPresenter(*this);
	}

	return ret;
}

// OFFSET: LEGO1 0x1000d490
void MxSoundPresenter::Destroy()
{
	Destroy(FALSE);
}
