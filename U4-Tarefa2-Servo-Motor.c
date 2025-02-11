#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PINO_SERVO 22 // Definição do pino do servo motor

// Função para converter um ângulo (0 a 180 graus) em um duty cycle apropriado
uint16_t angulo_para_duty(float angulo)
{
    float duty_min = 500.0f;  // Duty cycle correspondente a 0 graus (500µs)
    float duty_max = 2400.0f; // Duty cycle correspondente a 180 graus (2400µs)
    float duty = duty_min + (angulo / 180.0f) * (duty_max - duty_min);
    return (uint16_t)((duty / 20000.0f) * 65535.0f);
}

// Função para movimentar o servo para um determinado ângulo
void mover_servo(uint fatiamento, float angulo)
{
    pwm_set_gpio_level(PINO_SERVO, angulo_para_duty(angulo));
}

// Função de configuração do PWM para controle do servo motor
uint cofig()
{
    gpio_set_function(PINO_SERVO, GPIO_FUNC_PWM);            // Define o pino do servo como saída PWM
    uint fatiamento_pwm = pwm_gpio_to_slice_num(PINO_SERVO); // Obtém o slice do PWM para o pino
    pwm_config configuracao_pwm = pwm_get_default_config();  // Obtém configuração padrão do PWM
    pwm_config_set_clkdiv(&configuracao_pwm, 64.0f);         // Define o divisor de clock para controle de frequência
    pwm_config_set_wrap(&configuracao_pwm, 62500);           // Define o período do PWM
    pwm_init(fatiamento_pwm, &configuracao_pwm, true);       // Inicializa o PWM com as configurações definidas

    return fatiamento_pwm;
}

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial padrão

    uint fatiamento_pwm = cofig(); // Confgiura o PWM do servo e retorna o slice

    while (1)
    {
        // Movimenta o servo para 180 graus e acende o LED
        mover_servo(fatiamento_pwm, 180);
        sleep_ms(5000);

        // Movimenta o servo para 90 graus e apaga o LED
        mover_servo(fatiamento_pwm, 90);
        // gpio_put(PINO_LED, 0);
        sleep_ms(5000);

        // Movimenta o servo para 0 graus e acende o LED
        mover_servo(fatiamento_pwm, 0);
        sleep_ms(5000);

        // Movimento suave do servo de 500µs (0 graus) a 2400µs (180 graus)
        for (uint16_t duty = 500; duty <= 2400; duty += 5)
        {
            pwm_set_gpio_level(PINO_SERVO, (uint16_t)((duty / 20000.0f) * 65535.0f));
            sleep_ms(10);
        }

        // Movimento suave do servo de 2400µs (180 graus) a 500µs (0 graus)
        for (uint16_t duty = 2400; duty >= 500; duty -= 5)
        {
            pwm_set_gpio_level(PINO_SERVO, (uint16_t)((duty / 20000.0f) * 65535.0f));
            sleep_ms(10);
        }
    }
}
