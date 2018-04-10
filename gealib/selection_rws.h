#ifndef SELECTION_RWS_H
#define SELECTION_RWS_H

#include "selection.h"

namespace gealib {
	class selection_rws : public selection
	{
	public:
		void select(chromo_vec& current, chromo_vec& selected) override;
	};
}

#endif // !SELECTION_RWS_H





