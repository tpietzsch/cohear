#ifndef COHEAR_PASS_THROUGH_CALLBACK_DESCRIPTION_H__
#define COHEAR_PASS_THROUGH_CALLBACK_DESCRIPTION_H__

#include "CallbackDescription.h"
#include "PassThroughSlot.h"

namespace chr {

template <typename SignalType>
class PassThroughCallbackDescription : public CallbackDescription {

public:

	PassThroughCallbackDescription(PassThroughSlot* slot) :
		CallbackDescription(
				typeid(SignalType),
				typeid(*this),
				slot),
		_slot(slot) {}

	void* notifySlotConnect(detail::SlotBase* const slot) override final {

		_slot->addSlot(slot);
		return 0;
	}

	void notifySlotDisconnect(detail::SlotBase* const slot) override final {

		_slot->removeSlot(slot);
	}

private:

	// the slot to forward signals to
	PassThroughSlot* _slot;
};

} // namespace chr

#endif // COHEAR_PASS_THROUGH_CALLBACK_DESCRIPTION_H__

