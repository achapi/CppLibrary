ライブラリ集
名前に「にるれ」が含まれる人は使用料払ってください

## 構成

- `data_structure/`: データ構造・クエリ処理
- `algorithm/`: 配列・列に対するアルゴリズム
- `graph/`: グラフ
- `tree/`: 木
- `string/`: 文字列アルゴリズム
- `math/`: 数学・数論・代数
- `geometry/`: 幾何
- `utility/`: 全探索・小技
- `template/`: 提出用テンプレート
- `tools/`: 開発・検証用ツール

コードの追加・修正時は [`style.txt`](style.txt) の規約に従います。

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

| 分類 | ライブラリ | 内容 |
|---|---|---|
| データ構造 | `重み付きUnionFind.cpp` | ポテンシャル付きUnion-Find |
|  | `スパーステーブル.cpp` | 冪等演算の静的区間取得 |
|  | `双対セグ木.cpp` | 区間作用・一点取得 |
|  | `二進トライ木.cpp` | 集合のXOR最小値 |
|  | `BinaryTrie.cpp` | 多重集合に対応したBinary Trie |
|  | `ImplicitTreap.cpp` | 暗黙Treapによる列操作 |
|  | `LiChaoTree.cpp` | 座標圧縮Li Chao Tree |
|  | `LiChaoTree_online.cpp` | 動的Li Chao Tree |
|  | `SegmentTreeBeats.cpp` | Segment Tree Beats |
|  | `点加算長方形和.cpp` | 点加算・長方形和クエリ |
|  | `mo.cpp` | Mo's algorithm |
| グラフ | `最短経路.cpp` | Dijkstra、Bellman–Ford、Warshall–Floyd、経路復元 |
|  | `有向閉路検出.cpp` | 有向グラフの閉路検出 |
|  | `橋と関節点.cpp` | 関節点・橋 |
|  | `最小全域木.cpp` | Kruskal法 |
|  | `トポロジカルソート.cpp` | 辞書順最小トポロジカルソート |
| 木 | `最小共通祖先.cpp` | ダブリングLCA・距離・祖先ジャンプ |
|  | `重軽分解.cpp` | パス・部分木の区間分解 |
|  | `HLD.cpp` | Heavy-Light Decomposition |
|  | `木の直径.cpp` | 重み付き木の直径と経路 |
| 文字列 | `文字列アルゴリズム.cpp` | Z、KMP前処理、Manacher |
|  | `ローリングハッシュ.cpp` | mod $2^{61}-1$ Rolling Hash |
| 数学 | `整数論.cpp` | Miller–Rabin、Pollard's rho、線形篩、floor sum |
|  | `組合せ.cpp` | 階乗、二項係数、順列 |
|  | `行列.cpp` | 積、累乗、行列式 |
|  | `gcd畳み込み.cpp` | GCD convolution |
|  | `xor畳み込み.cpp` | XOR convolution |
| 幾何 | `幾何.cpp` | 点・外積・交差判定・凸包 |
|  | `偏角ソート.cpp` | 偏角順ソート |
|  | `凸包.cpp` | 凸包構築 |
|  | `長方形領域和.cpp` | 長方形の和集合の面積 |
