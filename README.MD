![alt text](image.png)
![alt text](image-1.png)
# 🚀 Projeto de Monitoramento com Display OLED e Sensor Ultrassônico

## 📑 Sumário
- [👤 Autor](#-autor)
- [📝 Descrição](#-descrição)
- [🔌 Esquema de Conexões](#-esquema-de-conexões)
- [✨ Funcionalidades](#-funcionalidades)
- [📚 Bibliotecas Utilizadas](#-bibliotecas-utilizadas)
- [⚙️ Como Compilar e Executar](#️-como-compilar-e-executar)
- [📂 Estrutura de Arquivos](#-estrutura-de-arquivos)
- [🤝 Contribuições](#-contribuições)

## 👤 Autor
**🎓 [Atenilton Santos de Souza Júnior]**    
🔗 [GitHub](https://github.com/ateniltonjr)

## 📝 Descrição
Projeto desenvolvido para **Raspberry Pi Pico W kit BitDogLab** que utiliza:

🖥️ Display OLED SSD1306 (128x64) via I2C  
📏 Sensor ultrassônico HC-SR04  
💡 LEDs e 🎵 buzzer para feedback visual/auditivo

O sistema mede distâncias com precisão e exibe alertas no display conforme a proximidade de objetos.

## 🔌 Esquema de Conexões
| Componentes      | Pino Pico| Emojis 
| Display SDA      | GP14     | 📡    
| Display SCL      | GP15     | 📡    
| Trigger (HC-SR04)| GP[9]    | 🔊    
| Echo (HC-SR04)   | GP[8]    | 👂    
| Buzzer           | GP[21]   | 🎵    
| LED Vermelho     | GP[13]   | 🔴    
| LED Azul         | GP[12]   | 🔵    
| LED Verde        | GP[11]   | 🟢    

## ✨ Funcionalidades
- 📏 Medição precisa de distância (0-400cm)
- 🖥️ Exibição gráfica no display OLED
- 🚨 Alertas visuais (LEDs) e sonoros (buzzer)
- 💬 Mensagens contextualizadas no display
- ⚡ Baixo consumo de energia

## 📚 Bibliotecas Utilizadas
- `pico/stdlib` (padrão)
- `hardware/i2c` (comunicação I2C)

## ⚙️ Como Compilar e Executar
1. Clone o repositório:
   ```bash
   git clone https://github.com/ateniltonjr/ultrassonico.git
   cd projeto-pico
Configure o ambiente:

bash
Copy
mkdir build && cd build
cmake ..
Compile:

bash
Copy
make -j4
Conecte o Pico no modo BOOTSEL (botão pressionado)

Copie o .uf2:

bash
Copy
cp wokwi_project.uf2 /media/ateniltonjr/RPI-RP2/
📂 Estrutura de Arquivos
Copy
📁 projeto-pico (Pasta C e H)
├── 📁 H
│   ├── 🖥️ display.h             # Interface do display
│   ├── 💻 display.c             # Implementação  
│   ├── 🏗️ ultrassonico.c        # Lógica principal
│   ├── 🖍️ ssd1306.h             # Driver OLED
│   ├── 🔤 font.h                # Fontes
│   ├── 💡 led_buzzer.h          # LEDs/buzzer
│   └── 📏 sensor_ultrassonico.h # Configurações do sensor ultrassônico
│   ├── 🌟 exibicao.h            # Exibe a leitura do sensor no monitor serial e no display
├── 📜 README.md
└── 📜 CMakeLists.txt


🤝 Contribuições
💡 Ideias e contribuições são bem-vindas!
🔧 Como contribuir:

Fork o projeto

Crie sua branch (git checkout -b feature/nova-funcionalidade)

Commit suas mudanças (git commit -m 'Adiciona nova funcionalidade')

Push para a branch (git push origin feature/nova-funcionalidade)

Abra um Pull Request

🌟 Dê uma ⭐ no repositório se gostou do projeto!