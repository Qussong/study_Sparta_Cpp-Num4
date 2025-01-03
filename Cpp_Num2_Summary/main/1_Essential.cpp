#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std ���

class Book
{
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};

class BookManager
{
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author)
    {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const
    {
        if (books.empty())
        {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        // �Ϲ����� for�� ���
        for (size_t i = 0; i < books.size(); i++)
        {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchBook(int option, std::string input) const
    {
        // option 1 : å ���� �˻�
        // option 2 : �۰� �˻�

        for (int i = 0; i < books.size(); ++i)
        {
            // å ���� �˻�
            if (1 == option)
            {
                if (books[i].title == input)
                {
                    cout << "- " << books[i].title << " by " << books[i].author << endl;
                    return;
                }
            }
            // �۰� �˻�
            else if (2 == option)
            {
                if (books[i].author == input)
                {
                    cout << "- " << books[i].title << " by " << books[i].author << endl;
                    return;
                }
            }
        }

        std::cout << "�Է��Ͻ� ������ å�� ã�� �� �����ϴ�." << std::endl;
    }
};

int main() {

    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true)
    {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;         // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl;    // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. ����" << endl;            // ���α׷� ����
        std::cout << "4. �˻�" << std::endl;  // å �˻�
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1)
        {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2)
        {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else if (choice == 4)
        {
            int option = -1;
            std::string input = "";
            // 4�� ����: �˻�
            std::cout << "�˻������� �������ּ��� (1:å����, 2:�۰�) : ";
            std::cin >> option;
            std::cout << "�˻� : ";
            std::cin >> input;
            manager.searchBook(option, input);
        }
        else
        {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
