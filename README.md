ライブラリ集
名前に「にるれ」が含まれる人は使用料払ってください

## 構成

- `data_structure/`: データ構造・クエリ処理
- `graph/`: グラフ
- `tree/`: 木
- `string/`: 文字列アルゴリズム
- `math/`: 数学・数論・代数
- `geometry/`: 幾何
- `utility/`: 全探索・小技
- `template/`: 提出用テンプレート
- `tools/`: 開発・検証用ツール

## verification-helperで検証

検証には
[`online-judge-tools/verification-helper`](https://github.com/online-judge-tools/verification-helper)
を使用します。

```sh
python3 -m venv .venv
. .venv/bin/activate
pip install -r requirements.txt
oj-verify run
```

`main` への push と pull request では、GitHub Actions が同じ検証を実行します。

## 頻出ライブラリ

ACLにある `dsu`、Fenwick Tree、Segment Tree、Lazy Segment Tree、最大流、
最小費用流、SCC、Two-SAT、modint、畳み込み、suffix arrayはACLを直接使います。
このリポジトリではACLにない、または補助が必要な次の機能を提供します。

| 分類 | ヘッダ | 内容 |
|---|---|---|
| データ構造 | `weighted_union_find.hpp` | ポテンシャル付きUnion-Find |
|  | `sparse_table.hpp` | 冪等演算の静的区間取得 |
|  | `dual_segment_tree.hpp` | 区間作用・一点取得 |
|  | `binary_trie.hpp` | 集合のXOR最小値 |
|  | `mo.hpp` | Mo's algorithm |
| グラフ | `shortest_path.hpp` | Dijkstra、Bellman–Ford、Warshall–Floyd、経路復元 |
|  | `lowlink.hpp` | 関節点・橋 |
|  | `minimum_spanning_tree.hpp` | Kruskal法 |
|  | `topological_sort.hpp` | 辞書順最小トポロジカルソート |
| 木 | `lowest_common_ancestor.hpp` | ダブリングLCA・距離・祖先ジャンプ |
|  | `heavy_light_decomposition.hpp` | パス・部分木の区間分解 |
|  | `tree_diameter.hpp` | 重み付き木の直径と経路 |
| 文字列 | `string_algorithms.hpp` | Z、KMP前処理、Manacher |
|  | `rolling_hash.hpp` | mod $2^{61}-1$ Rolling Hash |
| 数学 | `number_theory.hpp` | Miller–Rabin、Pollard's rho、線形篩、floor sum |
|  | `combinatorics.hpp` | 階乗、二項係数、順列 |
|  | `matrix.hpp` | 積、累乗、行列式 |
| 幾何 | `geometry.hpp` | 点・外積・交差判定・凸包 |
