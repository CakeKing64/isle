#ifndef MXOBJECTFACTORY_H
#define MXOBJECTFACTORY_H

#include "mxatomid.h"
#include "mxcore.h"

#define FOR_MXOBJECTFACTORY_OBJECTS(X)                                                                                 \
	X(MxPresenter)                                                                                                     \
	X(MxCompositePresenter)                                                                                            \
	X(MxVideoPresenter)                                                                                                \
	X(MxFlcPresenter)                                                                                                  \
	X(MxSmkPresenter)                                                                                                  \
	X(MxStillPresenter)                                                                                                \
	X(MxWavePresenter)                                                                                                 \
	X(MxMIDIPresenter)                                                                                                 \
	X(MxEventPresenter)                                                                                                \
	X(MxLoopingFlcPresenter)                                                                                           \
	X(MxLoopingSmkPresenter)                                                                                           \
	X(MxLoopingMIDIPresenter)

// VTABLE 0x100dc220
class MxObjectFactory : public MxCore {
public:
	MxObjectFactory();

	// OFFSET: LEGO1 0x10008f70
	inline virtual const char* ClassName() const override // vtable+0xc
	{
		// 0x100f0730
		return "MxObjectFactory";
	}

	// OFFSET: LEGO1 0x10008f80
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, MxObjectFactory::ClassName()) || MxCore::IsA(name);
	}

	virtual MxCore* Create(const char* p_name); // vtable 0x14
	virtual void Destroy(MxCore* p_object);     // vtable 0x18
private:
#define X(V) MxAtomId m_id##V;
	FOR_MXOBJECTFACTORY_OBJECTS(X)
#undef X
};

#endif // MXOBJECTFACTORY_H
