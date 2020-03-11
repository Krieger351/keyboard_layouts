/* Copyright 2019 COSEYFANNITUTTI
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LAYOUT_kc_65_ansi( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, K2E, \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40, K41, K42,                K46,           K49, K4A, K4B, K4C, K4D, K4E \
) LAYOUT_65_ansi( \
  KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, \
  KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, \
  KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B,      KC_##K2D, KC_##K2E, \
  KC_##K30,      KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_##K3E, \
  KC_##K40, KC_##K41, KC_##K42,                KC_##K46,           KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D, KC_##K4E \
)

#define L0 0
#define L1 1

#define KC_L1 MO(L1)
#define KC_____ _______
#define KC_RESET RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L0] = LAYOUT_kc_65_ansi(
   //┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
      GESC ,1    ,2    ,3    ,4    ,5    ,6    ,7    ,8    ,9    ,0    ,MINS ,EQL  ,BSPC       ,GRV  ,
   //├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┬─────┤
      TAB     ,Q    ,W    ,E    ,R    ,T    ,Y    ,U    ,I    ,O    ,P    ,LBRC ,RBRC ,BSLS    ,DEL  ,
   //├────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────────┬─────┤
      L1         ,A    ,S    ,D    ,F    ,G    ,H    ,J    ,K    ,L    ,SCLN ,QUOT ,ENT        ,PGUP ,
   //├───────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┼─────┤
      LSFT       ,Z    ,X    ,C    ,V    ,B    ,N    ,M    ,COMM ,DOT  ,SLSH ,RSFT       ,UP   ,PGDN ,
   //├─────┬─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┼─────┴──┬──┴─────┼─────┬─────┼─────┼─────┤
      LCTL ,LGUI ,LALT ,SPC                                ,RALT    ,L1      ,RCTL ,LEFT ,DOWN ,RGHT ),
   //└─────┴─────┴─────┴───────────────────────────────────┴────────┴────────┴─────┴─────┴─────┴─────┘

  [L1] = LAYOUT_kc_65_ansi(
    //┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
       GRV  ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,F7   ,F8   ,F9   ,F10  ,F11  ,F12  ,DEL        ,PSCR ,
    //├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┬─────┤
       ____    ,____ ,____ ,____ ,RESET,____ ,____ ,____ ,UP   ,____ ,____ ,____ ,____ ,____    ,____ ,
    //├────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────────┬─────┤
       ____       ,____ ,____ ,____ ,____ ,____ ,____ ,LEFT ,DOWN ,RGHT ,____ ,____ ,____       ,HOME ,
    //├───────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┼─────┤
       ____       ,____ ,____ ,____ ,____ ,____ ,____ ,____ ,____ ,____ ,____ ,____       ,____ ,END  ,
    //├─────┬─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┼─────┴──┬──┴─────┼─────┬─────┼─────┼─────┤
       ____ ,____ ,____ ,____                               ,____    ,____    ,____ ,____ ,____ ,____ ),
    //└─────┴─────┴─────┴───────────────────────────────────┴────────┴────────┴─────┴─────┴─────┴─────┘
};
