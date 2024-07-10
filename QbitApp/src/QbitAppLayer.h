#pragma once

#include "Qbit.h"

class QbitAppLayer : public Qbit::Layer
{
public:
	QbitAppLayer();
	virtual ~QbitAppLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Qbit::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Qbit::Event& e) override;
private:
	Qbit::OrthographicCameraController m_CameraController;
};

