#include "MenuPrincipal.h"

using namespace SpriteGoku;

// M�todo para inicializar el formulario
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MenuPrincipal());
	return 0;
}