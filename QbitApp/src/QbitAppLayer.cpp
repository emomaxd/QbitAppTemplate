#include "qbpch.h"
#include "QbitAppLayer.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

QbitAppLayer::QbitAppLayer()
	: Layer("QbitAppLayer"), m_CameraController(1600.0f / 900.0f)
{
}

void QbitAppLayer::OnAttach()
{
	QB_PROFILE_FUNCTION();
}

void QbitAppLayer::OnDetach()
{
	QB_PROFILE_FUNCTION();
}

void QbitAppLayer::OnUpdate(Qbit::Timestep ts)
{

	QB_PROFILE_FUNCTION();
	
	// Update
	m_CameraController.OnUpdate(ts);

	
	// Render
	Qbit::Renderer2D::ResetStats();

	{
		QB_PROFILE_SCOPE("RendererPrep");
		Qbit::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Qbit::RenderCommand::Clear();
	}

	{

		QB_PROFILE_SCOPE("Renderer - Draw");
		Qbit::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Qbit::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });

		Qbit::Renderer2D::DrawRotatedQuad({ -12.2f, -0.5f }, { 12.0f, 12.0f }, 30.0f, { 0.2f, 0.4f, 0.6f, 0.4f });

		Qbit::Renderer2D::EndScene();

		Qbit::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.2f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.2f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Qbit::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Qbit::Renderer2D::EndScene();
	}
	
}

void QbitAppLayer::OnImGuiRender()
{
	QB_PROFILE_FUNCTION();
	
	ImGui::Begin("Settings");

	auto stats = Qbit::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	float fps = ImGui::GetIO().Framerate;
	ImGui::Text("FPS: %.1f    %.2f ms", fps, 1000 * 1.0f / fps);

	ImGui::End();
	
}

void QbitAppLayer::OnEvent(Qbit::Event& e)
{
	m_CameraController.OnEvent(e);
}