# 🕹️ Crawl.exe - RPG de Terminal

**Crawl.exe** é um jogo de aventura em C, jogado totalmente no terminal. Enfrente monstros, desvie de armadilhas, interaja com NPCs e avance por fases desafiadoras enquanto explora dungeons perigosas!

---

## 📖 História

Você é um viajante solitário que decide explorar a misteriosa caverna de uma cidade distante. Movido pela curiosidade e desejo de aventura, entra sozinho no subterrâneo desconhecido, enfrentando perigos e mistérios ocultos nas profundezas.

---

## 🎯 Objetivo

Seu objetivo é chegar até o final da caverna, superando obstáculos, armadilhas e inimigos. Colete chaves, ative mecanismos e encontre passagens secretas para completar sua jornada com vida.

---

## 🎮 Como Jogar

### ✅ Objetivo  
Colete chaves, interaja com personagens, use teletransportes e sobreviva até a fase final.

### 🕹️ Controles

| Tecla | Ação                          |
|-------|-------------------------------|
| `W`   | Mover para cima               |
| `S`   | Mover para baixo              |
| `A`   | Mover para a esquerda         |
| `D`   | Mover para a direita          |
| `I`   | Interagir com NPCs ou objetos|

---

## 🧩 Elementos do Jogo

| Símbolo | Significado                          |
|---------|---------------------------------------|
| `&`     | Jogador                               |
| `P`     | NPCs                                  |
| `@`     | Chave                                 |
| `D`     | Porta fechada                         |
| `=`     | Porta aberta                          |
| `*`     | Parede                                |
| `#`     | Espinho (dano)                        |
| `O`     | Botão que abre passagens              |
| `X`     | Monstro bêbado (movimento aleatório)  |
| `V`     | Monstro inteligente (persegue jogador)|
| `>`     | Teletransporte                        |

---

## 🧠 Fases do Jogo

- **Village Level** – Fase introdutória com NPCs e coleta de chave.  
- **Level One** – Labirinto clássico com obstáculos.  
- **Level Two** – Fase com armadilhas, botões e teletransportes.  
- **Level Three** – Fase final com dois monstros e ambiente desafiador.

---

## ⚙️ Requisitos

- Compilador C (ex: `gcc`)  
- Ambiente Windows (usa `windows.h` e `conio.h`)  
- Terminal com suporte a UTF-8

---

## ▶️ Como Compilar e Rodar

```bash
gcc -o Crawl.exe main.c
./Crawl.exe
```

> 💡 Use um terminal com suporte UTF-8 e tamanho adequado para exibir todo o mapa corretamente.

---

## 👨‍💻 Créditos

- João Paulo Koury de Mendonça  
- Pedro Antônio de Souza Fernandes Filho

---

## 📜 Licença

Este projeto foi criado para fins educacionais. Uso não comercial permitido.
