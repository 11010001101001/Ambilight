## Addressable LED Controller (WS2812B + Arduino Nano)

DIY desktop LED controller based on **Arduino Nano** and **WS2812B** addressable LED strip.

![0](https://github.com/user-attachments/assets/f9e948fc-1455-479a-8f68-55d6ee22dafb)

### Hardware
- Power Supply: **5V 10A** (headroom, low heat)
- LED Strip: **WS2812B**, 5V, **97 LEDs**
- Controller: **Arduino Nano**
- Data resistor (recommended)
- Bulk capacitor on 5V rail

### Power & Wiring
- Arduino Nano powered via **USB (data + power)**
- LED strip powered from **external 5V PSU**
- **Common ground** between PSU and Arduino
- External PSU remains cool even at full white brightness

### Enclosure
- DIY black enclosure  
- Ventilation holes for passive cooling  
- Disassemblable design (bolts, not glue)
- Wires fixed with **hot glue** for strain relief and easy rework

### Features
- Compact and clean desktop form factor  
- Safe power design with current headroom  
- Easy to repair, modify, or upgrade  
- Visually minimal and tidy on the desk

![1](https://github.com/user-attachments/assets/c379ec4c-c220-4cf7-80a5-4eeaad4cf195)
![2](https://github.com/user-attachments/assets/10b9e97b-75d3-4b10-af07-612ff5283e0d)
![3](https://github.com/user-attachments/assets/49a6544a-823d-43fc-a972-926d75e7589c)
![4](https://github.com/user-attachments/assets/0d2c4d5d-f0ad-45d3-a119-eff3d8707359)
![5](https://github.com/user-attachments/assets/b197067b-4950-46fd-9127-2f342cd7f1c0)
![6](https://github.com/user-attachments/assets/393cb2a6-8a84-4eb6-9239-c8f2ad0017f6)
![7](https://github.com/user-attachments/assets/b866a38d-30e4-43ba-bf14-07fcb17224d8)
<img width="670" height="543" alt="1" src="https://github.com/user-attachments/assets/408d09fb-4512-4ba6-8304-35c719566c89" />
<img width="670" height="543" alt="2" src="https://github.com/user-attachments/assets/704feb25-e910-4b65-8fb9-5c51c70dfbbb" />

### Notes
- Some **Ambibox settings** are required: zones, directions, and layouts without corner LEDs.  
  Screenshots are included to save time.
- **Important:** the controller sketch uses **RGB** color order, while **Ambibox must be set to GRB**.
- If you mount the strip and set its direction the same way as I did, make sure to adjust **zone directions** accordingly in Ambibox.  
  It’s straightforward — you’ll figure it out.

## License

MIT

## Support

If you find this project useful:

TON: UQCQclFDQnQkHI4bJETisvn4QAZevjMWx5mjC3AErZaXvhlU  
USDT: TSiRAGH2apuygsgYP7Q9mS48WN4gDS6D5o  
BTC: 1HCZ7KsmVoiDrvPpnZ5jLQPp7mi7xWR7fi
