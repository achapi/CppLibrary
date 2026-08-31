ライブラリ集
名前に「にるれ」が含まれる人は使用料払ってください

## 構成

- `データ構造/`: データ構造・クエリ処理
- `グラフ/`: グラフ
- `木/`: 木
- `文字列/`: 文字列アルゴリズム
- `数学/`: 数学・数論・代数
- `幾何/`: 幾何
- `小技/`: 全探索・小技
- `テンプレート/`: 提出用テンプレート
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
| データ構造 | `重み付き素集合データ構造.hpp` | ポテンシャル付きUnion-Find |
|  | `スパーステーブル.hpp` | 冪等演算の静的区間取得 |
|  | `双対セグメント木.hpp` | 区間作用・一点取得 |
|  | `二進トライ木.hpp` | 集合のXOR最小値 |
|  | `モー法.hpp` | Mo's algorithm |
| グラフ | `最短経路.hpp` | Dijkstra、Bellman–Ford、Warshall–Floyd、経路復元 |
|  | `橋と関節点.hpp` | 関節点・橋 |
|  | `最小全域木.hpp` | Kruskal法 |
|  | `トポロジカルソート.hpp` | 辞書順最小トポロジカルソート |
| 木 | `最小共通祖先.hpp` | ダブリングLCA・距離・祖先ジャンプ |
|  | `重軽分解.hpp` | パス・部分木の区間分解 |
|  | `木の直径.hpp` | 重み付き木の直径と経路 |
| 文字列 | `文字列アルゴリズム.hpp` | Z、KMP前処理、Manacher |
|  | `ローリングハッシュ.hpp` | mod $2^{61}-1$ Rolling Hash |
| 数学 | `整数論.hpp` | Miller–Rabin、Pollard's rho、線形篩、floor sum |
|  | `組合せ.hpp` | 階乗、二項係数、順列 |
|  | `行列.hpp` | 積、累乗、行列式 |
| 幾何 | `幾何.hpp` | 点・外積・交差判定・凸包 |
