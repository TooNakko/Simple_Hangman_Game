# Simple_Hangman_Game
Mở file Hangman.cpp và chạy nó để chơi.
Chưa có thời gian chia code thành các hàm, rảnh sẽ làm.
Thêm từ KHÔNG CHỨA DẤU CÁCH trong file Words_list.txt đi kèm, mỗi dòng 1 từ và các từ sẽ được chọn ngẫu nhiên
Muốn chỉ định 1 từ? Thay dòng:
    `int random = rand() % (list.size() - 1) + 1;` 
trong Hangman.cpp bằng
    `int random = n-1;` 
với n là dòng thứ n chứa từ muốn chơi.
