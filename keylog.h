char keylog_str[24];
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    } else {
        name = ' ';
    }
    switch (keycode) {
        case KC_BSPC:
            snprintf(keylog_str, sizeof(keylog_str), "<<<<<");
            break;
        case 1:
            snprintf(keylog_str, sizeof(keylog_str), "^ RAI");
            break;
        case KC_LSFT:
            snprintf(keylog_str, sizeof(keylog_str), ">SFT<");
            break;
        case KC_RALT:
        case KC_LALT:
            snprintf(keylog_str, sizeof(keylog_str), ">ALT<");
            break;
        case KC_LGUI:
            snprintf(keylog_str, sizeof(keylog_str), ">CMD<");
            break;
        case KC_LCTL:
            snprintf(keylog_str, sizeof(keylog_str), ">CTL<");
            break;
        default:
            snprintf(keylog_str, sizeof(keylog_str), "> %c <", name);
            break;
    }
}