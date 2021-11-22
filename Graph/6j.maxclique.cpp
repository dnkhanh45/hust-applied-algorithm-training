#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Trả về kích thước của một tập con dựa trên bismask tương ứng
int count_node_of_subset(int s)
{
    int size = 0;
    int i = 1;
    while (s > 0)
    {
        if ((s & 1) == 1)
        {
            size += 1;
        }
        s = s >> 1;
        i += 1;
    }
    return size;
}

// Độ phức tạp: O(n^2.2^n)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    // Giá trị tương ứng với tập tất cả các đỉnh
    int all = (1 << n) - 1;
    // Một tập có phải là tập đỉnh của 1 đồ thị đầy đủ
    vector<bool> is_complete(all + 1, true);

    // Tập tất cả các cạnh
    set<int> all_edge;
    int edge;
    for (int i = 1; i <= n; i++)
    {
        for (int j = (i + 1); j <= n; j++)
        {
            edge = (1 << (i - 1)) + (1 << (j - 1));
            all_edge.insert(edge);
        }
    }

    // Xóa các cạnh được nối ra khỏi tập tất cả các cạnh
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge = (1 << (x - 1)) + (1 << (y - 1));
        all_edge.erase(edge);
    }

    // Với mỗi cạnh còn lại, tập đỉnh nào chứa 2 mút của cạnh đó thì không thể là tập đỉnh của 1 đồ thị đầy đủ
    for (auto e : all_edge)
    {
        for (int i = e; i <= all; i++)
        {
            if (is_complete[i])
            {
                if ((i | e) == i)
                {
                    is_complete[i] = false;
                }
            }
        }
    }

    // Lấy kích thước đồ thị đầy đủ lớn nhất
    int res = 0;
    for (int i = 1; i <= all; i++)
    {
        if (is_complete[i])
        {
            res = max(res, count_node_of_subset(i));
        }
    }

    cout << res;
    return 0;
}