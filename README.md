# G-scout
# 🚨 Gas Detection Rover – ESP32-Based Industrial Safety System

An affordable, Wi-Fi-enabled rover designed for hazardous industrial environments. It detects toxic gas leaks, sends real-time alerts via Blynk, and provides both audible and visual warnings. Built using ESP32, this system is designed to assist workers in areas like chemical plants, coal mines, and manufacturing units.

---

## 📌 Features

- 🔧 **Rover Movement** via Blynk App (Wi-Fi)
- 🌫️ **Gas Detection** using MQ-2 sensor
- 📊 **Live Sensor Data** on Blynk (Gauge + Chart)
- 🔔 **Push Notifications** for High Gas Levels
- 🔉 **Buzzer + LED Alerts** for immediate local response
- 💡 **Expandable** for future camera module or temperature/humidity sensors

---

## 🧠 Problem Domain

In hazardous industrial zones, toxic gas leaks can occur without warning, leading to potential disasters. Many small-scale industries lack access to costly IoT safety systems. This project provides a cost-effective and easily deployable solution that ensures real-time monitoring, alerting, and remote rover control to prevent such incidents.

---

## 🔧 Hardware Used

| Component               | Description                                      |
|------------------------|--------------------------------------------------|
| ESP32 Dev Board        | Wi-Fi enabled microcontroller                    |
| MQ-2 Gas Sensor        | For detecting combustible gas concentrations     |
| L298N Motor Driver     | Dual H-bridge motor controller for rover motion  |
| DC Motors (x2)         | For rover movement                               |
| Buzzer + LED           | For local alerts                                 |               
| Optional: OLED, DHT11  | (For future enhancement)                         |


---

## 🛠️ Software Tools

- **Arduino IDE** – For code development and flashing
- **Blynk IoT (v2.0)** – Dashboard to monitor and control the rover
- **Dabble App (initial testing only)** – Bluetooth interface (optional)
- **Git/GitHub** – Version control and documentation

---

## 🔄 System Workflow

1. ESP32 connects to Wi-Fi and initializes Blynk.
2. MQ-2 continuously monitors gas levels.
3. If threshold (>100) is breached:
   - Sends push notification via Blynk
   - Activates buzzer and LED alert
4. Rover movement is controlled remotely via Blynk App
5. Gas level data updates in real-time to Blynk (Gauge + Chart)

---

## 🔔 Alert Management

- Alerts sent once every 1 sec when gas exceeds threshold.
- Notification frequency adjustable via Blynk notification settings.
- Buzzer and LED blink continuously during high gas levels.

---

## 📈 Blynk Setup (v2.0)

- Create new template
- Add Widgets:
  - **Gauge**: V5 (Gas Value)
  - **Chart**: V5 (Gas Value history)
  - **Eventor**: For `gas_alert` event
  - **Notification Settings**: 1 per 1 second
- Copy **Auth Token**, **Template ID**, and **Device Name** to Arduino sketch

---

## 🧪 Testing & Validation

- Sensor tested under controlled smoke exposure
- Real-time push notifications confirmed
- Buzzer & LED respond instantly
- Rover controlled via phone through Wi-Fi

---

## 📦 Future Enhancements

- 📷 ESP32-CAM Integration for live video streaming
- 🌡️ DHT11/22 for temperature & humidity monitoring
- 💻 OLED screen for displaying local data
- 📡 SIM800L module for SMS-based alerts (offline mode)
- 📶 Auto/manual mode toggle via switch

---

## 🤝 Contributors

- **Harsh [Project Lead]** – Hardware, Code Integration, Testing  
- **NextShift AI** – System Design Guidance & Documentation Support

---

## 📜 License

This project is open-source under the [MIT License](LICENSE). You are free to use, modify, and distribute this project with credit.

---

## 🙌 Acknowledgments

- [Blynk IoT Platform](https://blynk.io/)
- [Arduino Community](https://arduino.cc/)
- Open-source libraries and tutorials that helped shape this project

---

## 🔗 Useful Links

- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Blynk Docs](https://docs.blynk.io/)

