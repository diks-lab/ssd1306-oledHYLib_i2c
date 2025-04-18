// Vfont middle
// 6*11 mFont
const unsigned char VfontHYm[][2][6] PROGMEM = {
 {{ 0x00,0x00,0x00,0x00,0x00,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x20 " "
 {{ 0x00,0x00,0xFC,0x00,0x00,0x00 }, { 0x00,0x00,0x0C,0x00,0x00,0x00 }}, // 0x21 "!"
 {{ 0x08,0x04,0x00,0x08,0x04,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x22 """
 {{ 0x10,0xFC,0x10,0x10,0xFC,0x10 }, { 0x01,0x0F,0x01,0x01,0x0F,0x01 }}, // 0x23 "#"
 {{ 0x38,0x44,0xFC,0x84,0x18,0x00 }, { 0x07,0x08,0x1F,0x08,0x07,0x00 }}, // 0x24 "$"
 {{ 0x38,0x44,0xB8,0x60,0x98,0x04 }, { 0x08,0x06,0x01,0x07,0x08,0x07 }}, // 0x25 "%"
 {{ 0x00,0xB8,0xC4,0x38,0x00,0x00 }, { 0x07,0x08,0x08,0x0B,0x04,0x0B }}, // 0x26 "&"
 {{ 0x00,0x00,0x14,0x0C,0x00,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x27 "'"
 {{ 0x00,0x00,0xF0,0x0C,0x00,0x00 }, { 0x00,0x00,0x03,0x0C,0x10,0x00 }}, // 0x28 "("
 {{ 0x00,0x00,0x0C,0xF0,0x00,0x00 }, { 0x00,0x10,0x0C,0x03,0x00,0x00 }}, // 0x29 ")"
 {{ 0x20,0x40,0xF0,0x40,0x20,0x00 }, { 0x02,0x01,0x07,0x01,0x02,0x00 }}, // 0x2A "*"
 {{ 0x80,0x80,0xF0,0x80,0x80,0x00 }, { 0x00,0x00,0x07,0x00,0x00,0x00 }}, // 0x2B "+"
 {{ 0x00,0x00,0x00,0x00,0x00,0x00 }, { 0x00,0x00,0x16,0x0E,0x00,0x00 }}, // 0x2C ","
 {{ 0x80,0x80,0x80,0x80,0x80,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x2D "-"
 {{ 0x00,0x00,0x00,0x00,0x00,0x00 }, { 0x00,0x00,0x06,0x06,0x00,0x00 }}, // 0x2E "."
 {{ 0x00,0x00,0x80,0x60,0x18,0x04 }, { 0x18,0x06,0x01,0x00,0x00,0x00 }}, // 0x2F "/"
 {{ 0xF8,0x04,0x04,0x04,0xF8,0x00 }, { 0x07,0x08,0x08,0x08,0x07,0x00 }}, // 0x30 "0"
 {{ 0x00,0x08,0xFC,0x00,0x00,0x00 }, { 0x00,0x00,0x0F,0x00,0x00,0x00 }}, // 0x31 "1"
 {{ 0x38,0x04,0x04,0xC4,0x38,0x00 }, { 0x0C,0x0A,0x09,0x08,0x08,0x00 }}, // 0x32 "2"
 {{ 0x18,0x44,0x44,0x44,0xB8,0x00 }, { 0x06,0x08,0x08,0x08,0x07,0x00 }}, // 0x33 "3"
 {{ 0x00,0x80,0x60,0x18,0xFC,0x00 }, { 0x02,0x03,0x02,0x02,0x0F,0x02 }}, // 0x34 "4"
 {{ 0x7C,0x44,0x44,0x44,0x84,0x00 }, { 0x06,0x08,0x08,0x08,0x07,0x00 }}, // 0x35 "5"
 {{ 0xF8,0x84,0x44,0x44,0x88,0x00 }, { 0x07,0x08,0x08,0x08,0x07,0x00 }}, // 0x36 "6"
 {{ 0x04,0x04,0x04,0xE4,0x1C,0x00 }, { 0x00,0x00,0x0F,0x00,0x00,0x00 }}, // 0x37 "7"
 {{ 0xB8,0x44,0x44,0x44,0xB8,0x00 }, { 0x07,0x08,0x08,0x08,0x07,0x00 }}, // 0x38 "8"
 {{ 0x78,0x84,0x84,0x44,0xF8,0x00 }, { 0x04,0x08,0x08,0x08,0x07,0x00 }}, // 0x39 "9"
 {{ 0x00,0x00,0x30,0x30,0x00,0x00 }, { 0x00,0x00,0x06,0x06,0x00,0x00 }}, // 0x3A ":"
 {{ 0x00,0x00,0x30,0x30,0x00,0x00 }, { 0x00,0x00,0x16,0x0E,0x00,0x00 }}, // 0x3B ";"
 {{ 0x80,0x40,0x20,0x10,0x08,0x00 }, { 0x00,0x01,0x02,0x04,0x08,0x00 }}, // 0x3C "<"
 {{ 0x20,0x20,0x20,0x20,0x20,0x00 }, { 0x02,0x02,0x02,0x02,0x02,0x00 }}, // 0x3D "="
 {{ 0x08,0x10,0x20,0x40,0x80,0x00 }, { 0x08,0x04,0x02,0x01,0x00,0x00 }}, // 0x3E ">"
 {{ 0x18,0x04,0x84,0x44,0x38,0x00 }, { 0x00,0x00,0x0D,0x00,0x00,0x00 }}, // 0x3F "?"
 {{ 0xF0,0xC8,0x24,0xE4,0x08,0xF0 }, { 0x03,0x04,0x09,0x09,0x09,0x05 }}, // 0x40 "@"
 {{ 0x00,0xF0,0x0C,0xF0,0x00,0x00 }, { 0x0F,0x02,0x02,0x02,0x0F,0x00 }}, // 0x41 "A"
 {{ 0xFC,0x44,0x44,0x44,0xB8,0x00 }, { 0x0F,0x08,0x08,0x08,0x07,0x00 }}, // 0x42 "B"
 {{ 0xF0,0x08,0x04,0x04,0x08,0x30 }, { 0x03,0x04,0x08,0x08,0x04,0x03 }}, // 0x43 "C"
 {{ 0xFC,0x04,0x04,0x08,0xF0,0x00 }, { 0x0F,0x08,0x08,0x04,0x03,0x00 }}, // 0x44 "D"
 {{ 0xFC,0x44,0x44,0x44,0x04,0x00 }, { 0x0F,0x08,0x08,0x08,0x08,0x00 }}, // 0x45 "E"
 {{ 0xFC,0x44,0x44,0x44,0x04,0x00 }, { 0x0F,0x00,0x00,0x00,0x00,0x00 }}, // 0x46 "F"
 {{ 0xF0,0x08,0x04,0x84,0x88,0x90 }, { 0x03,0x04,0x08,0x08,0x04,0x0F }}, // 0x47 "G"
 {{ 0xFC,0x40,0x40,0x40,0xFC,0x00 }, { 0x0F,0x00,0x00,0x00,0x0F,0x00 }}, // 0x48 "H"
 {{ 0x00,0x04,0xFC,0x04,0x00,0x00 }, { 0x00,0x08,0x0F,0x08,0x00,0x00 }}, // 0x49 "I"
 {{ 0x00,0x00,0x00,0x00,0xFC,0x00 }, { 0x06,0x08,0x08,0x08,0x07,0x00 }}, // 0x4A "J"
 {{ 0xFC,0x00,0xC0,0x30,0x0C,0x00 }, { 0x0F,0x01,0x00,0x01,0x06,0x08 }}, // 0x4B "K"
 {{ 0xFC,0x00,0x00,0x00,0x00,0x00 }, { 0x0F,0x08,0x08,0x08,0x08,0x08 }}, // 0x4C "L"
 {{ 0xFC,0xF0,0x00,0xF0,0xFC,0x00 }, { 0x0F,0x00,0x0F,0x00,0x0F,0x00 }}, // 0x4D "M"
 {{ 0xFC,0x38,0xC0,0x00,0xFC,0x00 }, { 0x0F,0x00,0x00,0x07,0x0F,0x00 }}, // 0x4E "N"
 {{ 0xF0,0x08,0x04,0x04,0x08,0xF0 }, { 0x03,0x04,0x08,0x08,0x04,0x03 }}, // 0x4F "O"
 {{ 0xFC,0x84,0x84,0x84,0x78,0x00 }, { 0x0F,0x00,0x00,0x00,0x00,0x00 }}, // 0x50 "P"
 {{ 0xF0,0x08,0x04,0x04,0x08,0xF0 }, { 0x03,0x04,0x08,0x09,0x06,0x0B }}, // 0x51 "Q"
 {{ 0xFC,0x84,0x84,0x84,0x78,0x00 }, { 0x0F,0x00,0x00,0x03,0x0C,0x00 }}, // 0x52 "R"
 {{ 0x38,0x44,0x44,0x84,0x18,0x00 }, { 0x07,0x08,0x08,0x08,0x07,0x00 }}, // 0x53 "S"
 {{ 0x04,0x04,0xFC,0x04,0x04,0x00 }, { 0x00,0x00,0x0F,0x00,0x00,0x00 }}, // 0x54 "T"
 {{ 0xFC,0x00,0x00,0x00,0xFC,0x00 }, { 0x07,0x08,0x08,0x08,0x07,0x00 }}, // 0x55 "U"
 {{ 0x3C,0xC0,0x00,0xC0,0x3C,0x00 }, { 0x00,0x03,0x0C,0x03,0x00,0x00 }}, // 0x56 "V"
 {{ 0xFC,0x00,0xFC,0x00,0xFC,0x00 }, { 0x00,0x0F,0x00,0x0F,0x00,0x00 }}, // 0x57 "W"
 {{ 0x0C,0x30,0xC0,0x30,0x0C,0x00 }, { 0x0C,0x03,0x00,0x03,0x0C,0x00 }}, // 0x58 "X"
 {{ 0x1C,0x60,0x80,0x60,0x1C,0x00 }, { 0x00,0x00,0x0F,0x00,0x00,0x00 }}, // 0x59 "Y"
 {{ 0x04,0x04,0xC4,0x34,0x0C,0x00 }, { 0x0C,0x0B,0x08,0x08,0x08,0x00 }}, // 0x5A "Z"
 {{ 0x00,0x00,0xFC,0x04,0x04,0x00 }, { 0x00,0x00,0x1F,0x10,0x10,0x00 }}, // 0x5B "["
 {{ 0x9C,0xE0,0x80,0xE0,0x9C,0x00 }, { 0x02,0x02,0x0F,0x02,0x02,0x00 }}, // 0x5C "\"
 {{ 0x00,0x04,0x04,0xFC,0x00,0x00 }, { 0x00,0x10,0x10,0x1F,0x00,0x00 }}, // 0x5D "]"
 {{ 0x10,0x08,0x04,0x08,0x10,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x5E "^"
 {{ 0x00,0x00,0x00,0x00,0x00,0x00 }, { 0x10,0x10,0x10,0x10,0x10,0x00 }}, // 0x5F "_"
 {{ 0x00,0x00,0x0C,0x14,0x20,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x60 "`"
 {{ 0x40,0x20,0x20,0x20,0xC0,0x00 }, { 0x06,0x09,0x09,0x09,0x07,0x08 }}, // 0x61 "a"
 {{ 0xFC,0x40,0x20,0x20,0xC0,0x00 }, { 0x0F,0x04,0x08,0x08,0x07,0x00 }}, // 0x62 "b"
 {{ 0xC0,0x20,0x20,0x20,0x40,0x00 }, { 0x07,0x08,0x08,0x08,0x04,0x00 }}, // 0x63 "c"
 {{ 0xC0,0x20,0x20,0x40,0xFC,0x00 }, { 0x07,0x08,0x08,0x04,0x0F,0x00 }}, // 0x64 "d"
 {{ 0xC0,0x20,0x20,0x20,0xC0,0x00 }, { 0x07,0x09,0x09,0x09,0x05,0x00 }}, // 0x65 "e"
 {{ 0x20,0xF8,0x24,0x24,0x00,0x00 }, { 0x00,0x0F,0x00,0x00,0x00,0x00 }}, // 0x66 "f"
 {{ 0x00,0xC0,0x20,0x20,0xC0,0x20 }, { 0x08,0x12,0x15,0x15,0x14,0x08 }}, // 0x67 "g"
 {{ 0xFC,0x40,0x20,0x20,0xC0,0x00 }, { 0x0F,0x00,0x00,0x00,0x0F,0x00 }}, // 0x68 "h"
 {{ 0x00,0x00,0xEC,0x00,0x00,0x00 }, { 0x00,0x00,0x07,0x08,0x00,0x00 }}, // 0x69 "i"
 {{ 0x00,0x00,0xEC,0x00,0x00,0x00 }, { 0x10,0x10,0x0F,0x00,0x00,0x00 }}, // 0x6A "j"
 {{ 0xFC,0x00,0x80,0x40,0x20,0x00 }, { 0x0F,0x01,0x02,0x04,0x08,0x00 }}, // 0x6B "k"
 {{ 0x00,0x00,0xFC,0x00,0x00,0x00 }, { 0x00,0x00,0x0F,0x00,0x00,0x00 }}, // 0x6C "l"
 {{ 0xE0,0x20,0xC0,0x20,0xC0,0x00 }, { 0x0F,0x00,0x0F,0x00,0x0F,0x00 }}, // 0x6D "m"
 {{ 0xE0,0x40,0x20,0x20,0xC0,0x00 }, { 0x0F,0x00,0x00,0x00,0x0F,0x00 }}, // 0x6E "n"
 {{ 0xC0,0x24,0x24,0x24,0xC4,0x00 }, { 0x07,0x08,0x08,0x08,0x07,0x00 }}, // 0x6F "o"
 {{ 0xC0,0x40,0x20,0x20,0xC0,0x00 }, { 0x1F,0x02,0x04,0x04,0x03,0x00 }}, // 0x70 "p"
 {{ 0xC0,0x20,0x20,0x40,0xC0,0x00 }, { 0x03,0x04,0x04,0x02,0x1F,0x00 }}, // 0x71 "q"
 {{ 0xE0,0x40,0x20,0x20,0x00,0x00 }, { 0x0F,0x00,0x00,0x00,0x00,0x00 }}, // 0x72 "r"
 {{ 0xC0,0x20,0x20,0x20,0x40,0x00 }, { 0x04,0x09,0x09,0x09,0x06,0x00 }}, // 0x73 "s"
 {{ 0x20,0xF8,0x20,0x20,0x00,0x00 }, { 0x00,0x07,0x08,0x08,0x00,0x00 }}, // 0x74 "t"
 {{ 0xE0,0x00,0x00,0x00,0xE0,0x00 }, { 0x07,0x08,0x08,0x04,0x0F,0x00 }}, // 0x75 "u"
 {{ 0x60,0x80,0x00,0x80,0x60,0x00 }, { 0x00,0x03,0x0C,0x03,0x00,0x00 }}, // 0x76 "v"
 {{ 0xE0,0x00,0xE0,0x00,0xE0,0x00 }, { 0x01,0x0E,0x01,0x0E,0x01,0x00 }}, // 0x77 "w"
 {{ 0x20,0xC0,0x00,0xC0,0x20,0x00 }, { 0x08,0x06,0x01,0x06,0x08,0x00 }}, // 0x78 "x"
 {{ 0x60,0x80,0x00,0x80,0x60,0x00 }, { 0x10,0x09,0x06,0x03,0x00,0x00 }}, // 0x79 "y"
 {{ 0x20,0x20,0x20,0xA0,0x60,0x00 }, { 0x0C,0x0A,0x09,0x08,0x08,0x00 }}, // 0x7A "z"
 {{ 0x00,0x00,0xC0,0x3C,0x04,0x00 }, { 0x00,0x00,0x00,0x1F,0x10,0x00 }}, // 0x7B "{"
 {{ 0x00,0x00,0xFC,0x00,0x00,0x00 }, { 0x00,0x00,0x1F,0x00,0x00,0x00 }}, // 0x7C "|"
 {{ 0x00,0x04,0x3C,0xC0,0x00,0x00 }, { 0x00,0x10,0x1F,0x00,0x00,0x00 }}, // 0x7D "}"
 {{ 0x08,0x04,0x04,0x08,0x08,0x04 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x7E "~"
 {{ 0x00,0x00,0x00,0x00,0x00,0x00 }, { 0x00,0x00,0x00,0x00,0x00,0x00 }}, // 0x7F ""
};

// Vfont small
const unsigned char VfontHYs[][5] PROGMEM = {
 { 0x00,0x00,0x00,0x00,0x00}, // 0x20 " "
 { 0x00,0x00,0x4f,0x00,0x00}, // 0x21 "!"
 { 0x00,0x07,0x00,0x07,0x00}, // 0x22 """
 { 0x14,0x7f,0x14,0x7f,0x14}, // 0x23 "#"
 { 0x24,0x2a,0x7f,0x2a,0x12}, // 0x24 "$"
 { 0x23,0x13,0x08,0x64,0x62}, // 0x25 "%"
 { 0x36,0x49,0x55,0x22,0x50}, // 0x26 "&"
 { 0x00,0x05,0x03,0x00,0x00}, // 0x27 "'"
 { 0x00,0x1c,0x22,0x41,0x00}, // 0x28 "("
 { 0x00,0x41,0x22,0x1c,0x00}, // 0x29 ")"
 { 0x14,0x08,0x3e,0x08,0x14}, // 0x2a "*"
 { 0x08,0x08,0x3e,0x08,0x08}, // 0x2b "+"
 { 0x00,0x50,0x30,0x00,0x00}, // 0x2c ","
 { 0x08,0x08,0x08,0x08,0x08}, // 0x2d "-"
 { 0x00,0x60,0x60,0x00,0x00}, // 0x2e "."
 { 0x20,0x10,0x08,0x04,0x02}, // 0x2f "/"
 { 0x3e,0x51,0x49,0x45,0x3e}, // 0x30 "0"
 { 0x00,0x42,0x7f,0x40,0x00}, // 0x31 "1"
 { 0x42,0x61,0x51,0x49,0x46}, // 0x32 "2"
 { 0x21,0x41,0x45,0x4b,0x30}, // 0x33 "3"
 { 0x18,0x14,0x12,0x7f,0x10}, // 0x34 "4"
 { 0x27,0x45,0x45,0x45,0x39}, // 0x35 "5"
 { 0x3c,0x4a,0x49,0x49,0x30}, // 0x36 "6"
 { 0x01,0x01,0x71,0x09,0x07}, // 0x37 "7"
 { 0x36,0x49,0x49,0x49,0x36}, // 0x38 "8"
 { 0x06,0x49,0x49,0x49,0x3e}, // 0x39 "9"
 { 0x00,0x36,0x36,0x00,0x00}, // 0x3a ":"
 { 0x00,0x56,0x36,0x00,0x00}, // 0x3b ";"
 { 0x08,0x14,0x22,0x41,0x00}, // 0x3c "<"
 { 0x14,0x14,0x14,0x14,0x14}, // 0x3d "="
 { 0x00,0x41,0x22,0x14,0x08}, // 0x3e ">"
 { 0x02,0x01,0x51,0x09,0x06}, // 0x3f "?"
 { 0x32,0x49,0x79,0x41,0x3e}, // 0x40 "@"
 { 0x7e,0x11,0x11,0x11,0x7e}, // 0x41 "A"
 { 0x7f,0x49,0x49,0x49,0x36}, // 0x42 "B"
 { 0x3e,0x41,0x41,0x41,0x22}, // 0x43 "C"
 { 0x7f,0x41,0x41,0x22,0x1c}, // 0x44 "D"
 { 0x7f,0x49,0x49,0x49,0x41}, // 0x45 "E"
 { 0x7f,0x09,0x09,0x09,0x01}, // 0x46 "F"
 { 0x3e,0x41,0x49,0x49,0x7a}, // 0x47 "G"
 { 0x7f,0x08,0x08,0x08,0x7f}, // 0x48 "H"
 { 0x00,0x41,0x7f,0x41,0x00}, // 0x49 "I"
 { 0x20,0x40,0x41,0x3f,0x01}, // 0x4a "J"
 { 0x7f,0x08,0x14,0x22,0x41}, // 0x4b "K"
 { 0x7f,0x40,0x40,0x40,0x40}, // 0x4c "L"
 { 0x7f,0x02,0x0c,0x02,0x7f}, // 0x4d "M"
 { 0x7f,0x04,0x08,0x10,0x7f}, // 0x4e "N"
 { 0x3e,0x41,0x41,0x41,0x3e}, // 0x4f "O"
 { 0x7f,0x09,0x09,0x09,0x06}, // 0x50 "P"
 { 0x3e,0x41,0x51,0x21,0x5e}, // 0x51 "Q"
 { 0x3f,0x09,0x19,0x29,0x46}, // 0x52 "R"
 { 0x46,0x49,0x49,0x49,0x31}, // 0x53 "S"
 { 0x01,0x01,0x7f,0x01,0x01}, // 0x54 "T"
 { 0x3f,0x40,0x40,0x40,0x3f}, // 0x55 "U"
 { 0x0f,0x30,0x40,0x30,0x0f}, // 0x56 "V"
 { 0x3f,0x40,0x38,0x40,0x3f}, // 0x57 "W"
 { 0x63,0x14,0x08,0x14,0x63}, // 0x58 "X"
 { 0x07,0x08,0x70,0x08,0x07}, // 0x59 "Y"
 { 0x61,0x51,0x49,0x45,0x43}, // 0x5a "Z"
 { 0x7f,0x41,0x41,0x00,0x00}, // 0x5b "["
 { 0x15,0x16,0x7c,0x16,0x15}, // 0x5c "\"
 { 0x00,0x41,0x41,0x7f,0x00}, // 0x5d "]"
 { 0x04,0x02,0x01,0x02,0x04}, // 0x5e "^"
 { 0x40,0x40,0x40,0x40,0x40}, // 0x5f "_"
 { 0x00,0x01,0x02,0x00,0x00}, // 0x60 "`"
 { 0x20,0x54,0x54,0x54,0x78}, // 0x61 "a"
 { 0x7f,0x48,0x44,0x44,0x38}, // 0x62 "b"
 { 0x38,0x44,0x44,0x44,0x20}, // 0x63 "c"
 { 0x38,0x44,0x44,0x48,0x7f}, // 0x64 "d"
 { 0x38,0x54,0x54,0x54,0x18}, // 0x65 "e"
 { 0x08,0x7e,0x09,0x01,0x02}, // 0x66 "f"
 { 0x0c,0x52,0x52,0x52,0x3e}, // 0x67 "g"
 { 0x7f,0x08,0x04,0x04,0x78}, // 0x68 "h"
 { 0x00,0x04,0x7d,0x00,0x00}, // 0x69 "i"
 { 0x20,0x40,0x44,0x3d,0x00}, // 0x6a "j"
 { 0x7f,0x10,0x28,0x44,0x00}, // 0x6b "k"
 { 0x00,0x41,0x3f,0x40,0x00}, // 0x6c "l"
 { 0x7c,0x04,0x38,0x04,0x78}, // 0x6d "m"
 { 0x7c,0x08,0x04,0x04,0x78}, // 0x6e "n"
 { 0x38,0x44,0x44,0x44,0x38}, // 0x6f "o"
 { 0xfc,0x24,0x24,0x24,0x18}, // 0x70 "p"
 { 0x18,0x24,0x24,0x28,0xfc}, // 0x71 "q"
 { 0x7c,0x08,0x04,0x04,0x00}, // 0x72 "r"
 { 0x48,0x54,0x54,0x54,0x20}, // 0x73 "s"
 { 0x04,0x3f,0x44,0x40,0x20}, // 0x74 "t"
 { 0x3c,0x40,0x40,0x20,0x7c}, // 0x75 "u"
 { 0x1c,0x20,0x40,0x20,0x1c}, // 0x76 "v"
 { 0x3c,0x40,0x38,0x40,0x3c}, // 0x77 "w"
 { 0x44,0x28,0x10,0x28,0x44}, // 0x78 "x"
 { 0x0c,0x50,0x50,0x50,0x3c}, // 0x79 "y"
 { 0x44,0x64,0x54,0x4c,0x44}, // 0x7a "z"
 { 0x00,0x08,0x36,0x41,0x00}, // 0x7b "{"
 { 0x00,0x00,0x7f,0x00,0x00}, // 0x7c "|"
 { 0x00,0x41,0x36,0x08,0x00}, // 0x7d "}"
 { 0x02,0x01,0x02,0x01,0x00}, // 0x7e "~"
 { 0x00,0x00,0x00,0x00,0x00}, // 0x7f " "
};
