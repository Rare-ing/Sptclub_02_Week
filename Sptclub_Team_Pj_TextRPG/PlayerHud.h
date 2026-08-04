#pragma once

class Player;

// 화면 좌측 상단에 플레이어 HP/MP 상태창을 그린다.
// 호출 전후로 커서 위치를 복원하므로, 로그를 이어 찍는 도중에 호출해도 안전하다.
void DrawPlayerHUD(Player* player);

// 전투 시작 시 한 번 호출해서, 이후 로그가 HUD 박스 아래부터 찍히도록 커서를 옮긴다.
void MoveCursorBelowPlayerHUD();
