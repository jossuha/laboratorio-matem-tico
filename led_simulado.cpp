#include <iostream>
#include <chrono>
#include <thread>

void encenderLed()
{
    std::cout << "[***] LED ENCENDIDO" << std::endl;
}

void apagarLed()
{
    std::cout << "[ ] LED APAGADO" << std::endl;
}

void parpadearLed(float frecuenciaHz, int ciclos)
{
    if (frecuenciaHz <= 0.0)
    {
        apagarLed();
        return;
    }

    int medioPeriodoMs = 500.0 / frecuenciaHz;

    for (int i = 0; i < ciclos; i++)
    {
        encenderLed();
        std::this_thread::sleep_for(std::chrono::milliseconds(medioPeriodoMs));
        apagarLed();
        std::this_thread::sleep_for(std::chrono::milliseconds(medioPeriodoMs));
    }
}

int main()
{
    parpadearLed(1.0, 5);
    return 0;
}
