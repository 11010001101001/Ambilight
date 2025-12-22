## Addressable LED Controller (WS2812B + Arduino Nano)

DIY desktop LED controller based on **Arduino Nano** and **WS2812B** addressable LED strip.

### Hardware
- Power Supply: **5V 10A** (headroom, low heat)
- LED Strip: **WS2812B**, 5V, **96 LEDs**
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
