#include <cstring>

#include "globals.h"
#include "our_descriptor.h"
#include "ps_auth.h"
#include "remapper.h"

const uint8_t REPORT_ID_MOUSE = 1;
const uint8_t REPORT_ID_KEYBOARD = 2;
const uint8_t REPORT_ID_CONSUMER = 3;

// -----------------------------
// Keyboard + Mouse (relative 16-bit X/Y, 16-bit wheel, AC Pan)
// -----------------------------
const uint8_t our_report_descriptor_kb_mouse[] = {
    0x05, 0x01,                // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,                // Usage (Keyboard)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_KEYBOARD,  //   Report ID (REPORT_ID_KEYBOARD)
    0x05, 0x07,                //   Usage Page (Kbrd/Keypad)
    0x19, 0xE0,                //   Usage Minimum (0xE0)
    0x29, 0xE7,                //   Usage Maximum (0xE7)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x08,                //   Report Count (8)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x19, 0x04,                //   Usage Minimum (0x04)
    0x29, 0x73,                //   Usage Maximum (0x73)
    0x95, 0x70,                //   Report Count (112)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x19, 0x87,                //   Usage Minimum (0x87)
    0x29, 0x8B,                //   Usage Maximum (0x8B)
    0x95, 0x05,                //   Report Count (5)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0x90,                //   Usage (0x90)
    0x09, 0x91,                //   Usage (0x91)
    0x95, 0x02,                //   Report Count (2)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x95, 0x01,                //   Report Count (1)
    0x81, 0x03,                //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x85, REPORT_ID_LEDS,      //   Report ID (REPORT_ID_LEDS)
    0x05, 0x08,                //   Usage Page (LEDs)
    0x95, 0x05,                //   Report Count (5)
    0x19, 0x01,                //   Usage Minimum (Num Lock)
    0x29, 0x05,                //   Usage Maximum (Kana)
    0x91, 0x02,                //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x95, 0x01,                //   Report Count (1)
    0x75, 0x03,                //   Report Size (3)
    0x91, 0x03,                //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,                      // End Collection

    0x05, 0x01,                   // Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                   // Usage (Mouse)
    0xA1, 0x01,                   // Collection (Application)
    0x05, 0x01,                   //   Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                   //   Usage (Mouse)
    0xA1, 0x02,                   //   Collection (Logical)
    0x85, REPORT_ID_MOUSE,        //     Report ID (REPORT_ID_MOUSE)
    0x09, 0x01,                   //     Usage (Pointer)
    0xA1, 0x00,                   //     Collection (Physical)
    0x05, 0x09,                   //       Usage Page (Button)
    0x19, 0x01,                   //       Usage Minimum (0x01)
    0x29, 0x08,                   //       Usage Maximum (0x08)
    0x95, 0x08,                   //       Report Count (8)
    0x75, 0x01,                   //       Report Size (1)
    0x25, 0x01,                   //       Logical Maximum (1)
    0x81, 0x02,                   //       Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,                   //       Usage Page (Generic Desktop Ctrls)
    0x09, 0x30,                   //       Usage (X)
    0x09, 0x31,                   //       Usage (Y)
    0x95, 0x02,                   //       Report Count (2)
    0x75, 0x10,                   //       Report Size (16)
    0x16, 0x00, 0x80,             //       Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //       Logical Maximum (32767)
    0x81, 0x06,                   //       Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xA1, 0x02,                   //       Collection (Logical)
    0x85, REPORT_ID_MULTIPLIER,   //         Report ID (REPORT_ID_MULTIPLIER)
    0x09, 0x48,                   //         Usage (Resolution Multiplier)
    0x95, 0x01,                   //         Report Count (1)
    0x75, 0x02,                   //         Report Size (2)
    0x15, 0x00,                   //         Logical Minimum (0)
    0x25, 0x01,                   //         Logical Maximum (1)
    0x35, 0x01,                   //         Physical Minimum (1)
    0x45, RESOLUTION_MULTIPLIER,  //         Physical Maximum (RESOLUTION_MULTIPLIER)
    0xB1, 0x02,                   //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, REPORT_ID_MOUSE,        //         Report ID (REPORT_ID_MOUSE)
    0x09, 0x38,                   //         Usage (Wheel)
    0x35, 0x00,                   //         Physical Minimum (0)
    0x45, 0x00,                   //         Physical Maximum (0)
    0x16, 0x00, 0x80,             //         Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //         Logical Maximum (32767)
    0x75, 0x10,                   //         Report Size (16)
    0x81, 0x06,                   //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                         //       End Collection
    0xA1, 0x02,                   //       Collection (Logical)
    0x85, REPORT_ID_MULTIPLIER,   //         Report ID (REPORT_ID_MULTIPLIER)
    0x09, 0x48,                   //         Usage (Resolution Multiplier)
    0x75, 0x02,                   //         Report Size (2)
    0x15, 0x00,                   //         Logical Minimum (0)
    0x25, 0x01,                   //         Logical Maximum (1)
    0x35, 0x01,                   //         Physical Minimum (1)
    0x45, RESOLUTION_MULTIPLIER,  //         Physical Maximum (RESOLUTION_MULTIPLIER)
    0xB1, 0x02,                   //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x35, 0x00,                   //         Physical Minimum (0)
    0x45, 0x00,                   //         Physical Maximum (0)
    0x75, 0x04,                   //         Report Size (4)
    0xB1, 0x03,                   //         Feature (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, REPORT_ID_MOUSE,        //         Report ID (REPORT_ID_MOUSE)
    0x05, 0x0C,                   //         Usage Page (Consumer)
    0x16, 0x00, 0x80,             //         Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //         Logical Maximum (32767)
    0x75, 0x10,                   //         Report Size (16)
    0x0A, 0x38, 0x02,             //         Usage (AC Pan)
    0x81, 0x06,                   //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                         //       End Collection
    0xC0,                         //     End Collection
    0xC0,                         //   End Collection
    0xC0,                         // End Collection

    0x05, 0x0C,                // Usage Page (Consumer)
    0x09, 0x01,                // Usage (Consumer Control)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_CONSUMER,  //   Report ID (REPORT_ID_CONSUMER)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x09, 0xB5,                //   Usage (Scan Next Track)
    0x09, 0xB6,                //   Usage (Scan Previous Track)
    0x09, 0xB7,                //   Usage (Stop)
    0x09, 0xCD,                //   Usage (Play/Pause)
    0x09, 0xE2,                //   Usage (Mute)
    0x09, 0xE9,                //   Usage (Volume Increment)
    0x09, 0xEA,                //   Usage (Volume Decrement)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x07,                //   Report Count (7)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x0B,                //   Usage Page (Telephony)
    0x09, 0x2F,                //   Usage (Phone Mute)
    0x95, 0x01,                //   Report Count (1)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                      // End Collection
};

// -----------------------------
// Absolute mouse variant (already 16-bit axes here)
// -----------------------------
const uint8_t our_report_descriptor_absolute[] = {
    0x05, 0x01,                // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,                // Usage (Keyboard)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_KEYBOARD,  //   Report ID (REPORT_ID_KEYBOARD)
    0x05, 0x07,                //   Usage Page (Kbrd/Keypad)
    0x19, 0xE0,                //   Usage Minimum (0xE0)
    0x29, 0xE7,                //   Usage Maximum (0xE7)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x08,                //   Report Count (8)
    0x81, 0x02,                //   Input (...)
    0x19, 0x04, 0x29, 0x73, 0x95, 0x70, 0x81, 0x02,
    0x19, 0x87, 0x29, 0x8B, 0x95, 0x05, 0x81, 0x02,
    0x09, 0x90, 0x09, 0x91, 0x95, 0x02, 0x81, 0x02,
    0x95, 0x01, 0x81, 0x03,
    0x85, REPORT_ID_LEDS,
    0x05, 0x08, 0x95, 0x05, 0x19, 0x01, 0x29, 0x05, 0x91, 0x02,
    0x95, 0x01, 0x75, 0x03, 0x91, 0x03,
    0xC0,

    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01,
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x02,
    0x85, REPORT_ID_MOUSE, 0x09, 0x01, 0xA1, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x08, 0x95, 0x08, 0x75, 0x01, 0x25, 0x01, 0x81, 0x02,
    0x05, 0x01, 0x09, 0x30, 0x09, 0x31,
    0x95, 0x02, 0x75, 0x10,
    0x16, 0x00, 0x00,             // Logical Min (0) for absolute variant
    0x26, 0xFF, 0x7F,             // Logical Max (32767)
    0x81, 0x02,                   // Input (Abs)
    0xA1, 0x02,
    0x85, REPORT_ID_MULTIPLIER, 0x09, 0x48, 0x95, 0x01, 0x75, 0x02,
    0x15, 0x00, 0x25, 0x01, 0x35, 0x01, 0x45, RESOLUTION_MULTIPLIER, 0xB1, 0x02,
    0x85, REPORT_ID_MOUSE, 0x09, 0x38, 0x35, 0x00, 0x45, 0x00,
    0x16, 0x00, 0x80, 0x26, 0xFF, 0x7F, 0x75, 0x10, 0x81, 0x06,
    0xC0,
    0xA1, 0x02,
    0x85, REPORT_ID_MULTIPLIER, 0x09, 0x48, 0x75, 0x02,
    0x15, 0x00, 0x25, 0x01, 0x35, 0x01, 0x45, RESOLUTION_MULTIPLIER, 0xB1, 0x02,
    0x35, 0x00, 0x45, 0x00, 0x75, 0x04, 0xB1, 0x03,
    0x85, REPORT_ID_MOUSE, 0x05, 0x0C,
    0x16, 0x00, 0x80, 0x26, 0xFF, 0x7F, 0
