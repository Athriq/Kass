#include <Kass.h>

class Sandbox : public Kass::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Kass::Application* Kass::CreateApplication() {
	return new Sandbox();
}