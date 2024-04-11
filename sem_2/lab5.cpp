#include <iostream>
#include <vector>
#include <stack>

// Перечисление для направлений ребер
enum direction {
    direction_NONE = 0,
    direction_AB = 1,
    direction_BOTH = 2,
};

// Структура вершины
struct Vertex {
    int dest;
    int weight;
    direction Path;
};

// Шаблон класса
template <size_t Rows_Colm>
class Graph {
    int q_Vert; // количество вершин
    std::vector<std::vector<Vertex>> adjList; // список смежности

    // Метод для добавления вершины
    void addVertex(int src, int dest, int weight, direction _Path) {
        Vertex vert;
        vert.dest = dest;
        vert.weight = weight;
        vert.Path = _Path;
        adjList[src].push_back(vert);
    }

    // Метод обхода в глубину
    void DFS(int v, std::vector<bool>& visited, std::stack<int>& SCC) {
        visited[v] = true;

        for (const auto& edge : adjList[v]) {
            int u = edge.dest;
            if (!visited[u] && edge.Path != direction_NONE) {
                DFS(u, visited, SCC);
            }
        }
        SCC.push(v);
    }

    // Вспомогательный метод для обхода в глубину
    void DFSUtil(int v, std::vector<bool>& visited, std::vector<int>& scc_vec) {
        visited[v] = true;
        scc_vec.push_back(v);

        for (const auto& edge : adjList[v]) {
            int u = edge.dest;
            if (!visited[u] && edge.Path != direction_NONE) {
                DFSUtil(u, visited, scc_vec);
            }
        }
    }

    // Метод для получения транспонированного графа
    Graph<Rows_Colm> getTranspose() {
        Graph<Rows_Colm> transposedGraph;
        transposedGraph.q_Vert = q_Vert;
        transposedGraph.adjList.resize(q_Vert);

        for (int v = 0; v < q_Vert; ++v) {
            for (const auto& edge : adjList[v]) {
                transposedGraph.addVertex(edge.dest, v, edge.weight, edge.Path);
            }
        }

        return transposedGraph;
    }

public:
    // Конструктор класса
    Graph() : q_Vert(Rows_Colm) {
        adjList.resize(q_Vert);
    }

    // Статический метод для создания графа из инициализаторов
    static Graph<Rows_Colm> create(std::initializer_list<std::initializer_list<std::pair<int, int>>> data) {
        Graph<Rows_Colm> graph;
        int rowIndx = 0;
        for (auto row : data) {
            int colmIndx = 0;
            for (auto val : row) {
                if (val.first != 0)
                    graph.addVertex(rowIndx, colmIndx, val.first, static_cast<direction>(val.second));
                ++colmIndx;
            }
            ++rowIndx;
        }
        return graph;
    }

    // Метод для вывода графа
    void printGraph() {
        for (int i = 0; i < q_Vert; i++) {
            std::cout << "Ñïèñîê ñìåæíîñòè âåðøèíû " << i + 1 << ": ";
            for (const auto& edge : adjList[i]) {
                std::cout << edge.dest + 1 << " ";
            }
            std::cout << std::endl;
        }
    }

    // Метод для нахождения сильно связанных компонент
    void findSCC() {
        std::vector<bool> visited(q_Vert, false);
        std::stack<int> SCC;

        for (int v = 0; v < q_Vert; ++v) {
            if (!visited[v]) {
                DFS(v, visited, SCC);
            }
        }

        Graph<Rows_Colm> transposedGraph = getTranspose();
        visited.assign(q_Vert, false);

        std::vector<std::vector<int>> SCCs;

        while (!SCC.empty()) {
            int v = SCC.top();
            SCC.pop();
            if (!visited[v]) {
                std::vector<int> scc_vec;
                transposedGraph.DFSUtil(v, visited, scc_vec);
                SCCs.push_back(scc_vec);
            }
        }

        for (const auto& SCC : SCCs) {
            std::cout << "Сильно связанная компонента: ";
            for (int v : SCC) {
                std::cout << v + 1 << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    setlocale(LC_ALL, "ru");

    // Создание графа и вывод информации
    auto graph = Graph<9>::create({
         { {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
         { {1, 0}, {0, 0}, {0, 0}, {1, 1}, {1, 2}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
         { {1, 0}, {0, 0}, {0, 0}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
         { {0, 0}, {1, 0}, {1, 2}, {0, 0}, {1, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
         { {0, 0}, {1, 2}, {0, 0}, {1, 2}, {0, 1}, {1, 1}, {0, 0}, {0, 0}, {0, 0} },
         { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
         { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
         { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 2} },
         { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 2}, {0, 1} }
        });

    graph.printGraph();
    std::cout << "Сильно связанные компоненты: " << std::endl;
    graph.findSCC();

    return 0;
}
