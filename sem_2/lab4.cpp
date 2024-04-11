#include <iostream>
#include <vector>
#include <queue>

// Объявление структуры вершины графа
struct Vertex {
	int dest; // номер вершины, в которую идет ребро
	int weight; // вес ребра
};

// Шаблон класса графа с матрицей смежности
template <size_t Rows_Colm>
class Graph {
	int q_Vert; // количество вершин
	std::vector <std::vector<Vertex>> adjList; // список смежности

	// Метод для добавления ребер в список смежности
	void addVertex(int src, int dest, int weight) {
		Vertex vert;
		vert.dest = dest;
		vert.weight = weight;
		adjList[src].push_back(vert);
	}
public:
	// Конструктор класса
	Graph() : q_Vert(Rows_Colm) {
		adjList.resize(q_Vert);
	}

	// Статический метод создания графа из инициализирующего списка
	static Graph<Rows_Colm> create(std::initializer_list<std::initializer_list<int>> data) {
		Graph <Rows_Colm> graph;
		int rowIndx = 0;
		for (auto row : data) {
			int colmIndx = 0;
			for (auto val : row) {
				if (val != 0)
					graph.addVertex(rowIndx, colmIndx, val);
				++colmIndx;
			}
			++rowIndx;
		}
		return graph;
	}

	// Метод для вывода списка смежности графа в консоль
	void printGraph() {
		for (int i = 0; i < q_Vert; i++) {
			std::cout << "Список смежности вершины " << i + 1 << ": ";
			for (const auto& edge : adjList[i]) {
				std::cout << edge.dest + 1 << " ";
			}
			std::cout << std::endl;
		}
	}

	// Метод обхода графа в глубину
	void DFS(int v, std::vector<bool>& visited) {
		visited[v] = true;
		std::cout << (v + 1) << ' ';

		for (const auto& edge : adjList[v]) {
			int u = edge.dest;
			if (!visited[u]) {
				DFS(u, visited);
			}
		}
	}

	// Метод для поиска связных компонент графа
	void findConnectedComponents() {
		std::vector<bool> visited(q_Vert, false);

		for (int v = 0; v < q_Vert; ++v) {
			if (!visited[v]) {
				DFS(v, visited);
				std::cout << std::endl;
			}
		}
	}
};



int main() {
	setlocale(LC_ALL, "ru");

	// Создание графа и инициализация его данными
	auto graph = Graph<9>::create({
		{0, 1, 1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0 ,1},
		{0, 0, 0, 0, 0, 0, 0, 1, 0}
		});

	int nv = 0;

	// Вывод информации о связных компонентах графа
	std::cout << "Компоненты связности при обходе DFS : " << std::endl;
	graph.findConnectedComponents();
	return 0;
}
