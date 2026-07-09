#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class User {
public:
  int id;
  int tuoi;
  string name;
  void thay_pass(string x) { pass = x; }
  string get_pass() const { return pass; } // thêm const ở đây

private:
  string pass;
};

int main() {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  vector<User> nguoi_dung;
  int next_id = 1; // id tự tăng

  vector<string> a = {"ĐĂNG KÍ",
                      "ĐĂNG NHẬP",
                      "THÊM NGƯỜI DÙNG",
                      "DANH SÁCH NGƯỜI DÙNG",
                      "XEM 1 NGƯỜI DÙNG CỤ THỂ",
                      "THOÁT"};
  vector<string> font_dang_ki = {
      "ENTER YOUR NAME: ", "AGE: ", "PASS: ", "NHẬP LẠI PASS ĐỂ NHỚ: "};

  for (int i = 0; i < 6; i++) {
    cout << i + 1 << ".    " << a[i] << "\n";
  }

  while (1) {
    cout << "ENTER YOUR CHOICE: ";
    int n;
    cin >> n;

    if (cin.fail()) { // xử lý khi nhập không phải số
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "VUI LÒNG NHẬP SỐ HỢP LỆ!\n";
      continue;
    }

    switch (n) {
    case 1: {
      User user_new;
      string pass = "", pass2 = "";

      cout << "1.  " << font_dang_ki[0] << ": ";
      cin.ignore(); // dọn '\n' sót lại từ cin >> n
      getline(cin, user_new.name);

      cout << "2.  " << font_dang_ki[1] << ": ";
      cin >> user_new.tuoi;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "TUỔI KHÔNG HỢP LỆ, ĐĂNG KÍ THẤT BẠI!\n";
        break;
      }

      cout << "3.  " << font_dang_ki[2] << ": ";
      cin >> pass;

      cout << "4.  " << font_dang_ki[3] << ": ";
      cin >> pass2;

      if (pass == pass2) {
        user_new.id = next_id++;
        user_new.thay_pass(pass);
        nguoi_dung.push_back(user_new);
        cout << "ĐĂNG KÍ THÀNH CÔNG! ID CỦA BẠN LÀ: " << user_new.id << "\n";
      } else {
        cout << "MẬT KHẨU KHÔNG KHỚP, ĐĂNG KÍ THẤT BẠI!\n";
      }
      break;
    }
    case 2: {
      cout << "NAME: ";
      cin.ignore(); // chỉ 1 lần duy nhất, trước getline đầu tiên
      string name;
      getline(cin, name);

      cout << "PASS: ";
      string pass;
      getline(cin, pass); // KHÔNG ignore lại ở đây

      bool login_ok = false;
      for (const auto &u : nguoi_dung) {
        if (u.name == name && u.get_pass() == pass) {
          login_ok = true;
          break;
        }
      }

      cout << (login_ok ? "CHÚC MỪNG!\n" : "FAILED!\n");
      break;
    }
    case 4: {
      cout << left << setw(6) << "ID" << setw(20) << "NAME" << setw(6) << "AGE"
           << "\n";
      cout << string(32, '-') << "\n";

      for (const auto &i : nguoi_dung) {
        cout << left << setw(6) << i.id << setw(20) << i.name << setw(6)
             << i.tuoi << "\n";
      }
      break;
    }
    case 5: {
      cout << "ENTER YOUR ID: ";
      int x;
      cin >> x;
      bool tim_thay = 0;
      for (auto i : nguoi_dung) {
        if (i.id == x) {
          cout << "ID: " << i.id << "\n";
          cout << "NAME: " << i.name << "\n";
          cout << "AGE: " << i.tuoi << "\n";
          tim_thay = 1;
          break;
        }
      }
      if (tim_thay == 0) {
        cout << "NOT FOUND!!!\n";
      }
      break;
    }
    case 6:
      cout << "TẠM BIỆT!\n";
      return 0;
    default:
      cout << "LỰA CHỌN KHÔNG HỢP LỆ!\n";
      break;
    }
  }
  return 0;
}