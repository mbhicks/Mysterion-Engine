#include "MysterionEngine.h"
#include "CorrectionComponent.h"
namespace MysterionEngine
{
	CorrectionService::CorrectionService() : Service("Correction")
	{}
	void CorrectionService::performCorrectionService(double deltaTime)
	{
		std::forward_list<Component*> *components = this->getComponents();
		CorrectionComponent *component;
		for (std::forward_list<Component*>::iterator it = components->begin(); it != components->end(); ++it)
		{
			component = (CorrectionComponent*)(*it);
			component->correct(deltaTime);
		}
	}
	void CorrectionService::pause()
	{}
	void CorrectionService::resume()
	{}
};