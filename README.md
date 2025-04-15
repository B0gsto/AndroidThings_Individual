# 🟢 ESP8266 + Blynk: Monitorizare senzor analog + control LED

Acest proiect Arduino permite citirea unui senzor analog (ex: MQ-7 pentru monoxid de carbon, sau senzor de lumină) folosind un **ESP8266 (NodeMCU)** și afișarea valorii în aplicația **Blynk IoT**, alături de aprinderea unui LED roșu sau verde în funcție de nivelul citit.

---

## 🔧 Componente necesare

- ESP8266 NodeMCU
- Senzor analog (ex: gaz, CO)
- 2x LED-uri (verde și roșu)
- Conexiune WiFi 2.4GHz
- Cont Blynk IoT

---

## 📱 Ce face proiectul

- Citește valoarea de pe pinul analog **A0**
- Trimite această valoare în aplicația Blynk (`V0`)
- Aprinde LED-ul roșu dacă valoarea depășește pragul de **300**
- Aprinde LED-ul verde dacă valoarea este sub acest prag

---

## 🔌 Conexiuni hardware

| Componentă     | ESP8266 Pin |
|----------------|-------------|
| LED Verde      | D4 (GPIO2)  |
| LED Roșu       | D5 (GPIO14) |
| Senzor (Signal)| A0          |
| Senzor (VCC)   | 3.3V        |
| Senzor (GND)   | GND         |

---

## 💻 Instalare și rulare

1. Descarcă biblioteca **Blynk** din Library Manager (Arduino IDE)
2. Creează un **template nou în Blynk Console**
3. Copiază în cod:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_TEMPLATE_NAME`
   - `BLYNK_AUTH_TOKEN`
4. Configurează numele rețelei WiFi și parola:

```cpp
char ssid[] = "Numele_Tau_WiFi";
char pass[] = "Parola_Ta";
