#pragma once

extern Dojo::Application* Dojo::CreateApplication();

int main(int argc, char** argv)
{
	Dojo::Log::Init();

	//DOJO_CORE_TRACE("DOJO ONE IS ALIVE");

	auto app = Dojo::CreateApplication();

	app->Run();

	app->DestroyAll();

	//DOJO_CORE_TRACE("DOJO APP CLOSING");

	delete app;
}