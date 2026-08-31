ライブラリ集
名前に「にるれ」が含まれる人は使用料払ってください

## 構成

- `data_structure/`: データ構造・クエリ処理
- `graph/`: グラフ・木
- `string/`: 文字列アルゴリズム
- `math/`: 数学・数論・代数
- `geometry/`: 幾何
- `utility/`: 全探索・小技
- `template/`: 提出用テンプレート
- `tools/`: 開発・検証用ツール

## Library Checkerをローカルで実行

`g++`、`git`、`python3`、Pythonの`venv`が必要です。初回実行時に公式の
`library-checker-problems`と依存パッケージを`.yosupo/`へ取得します。

```sh
tools/yosupo-test <問題名> <提出コード.cpp> [1ケースの制限秒数]
```

例:

```sh
tools/yosupo-test unionfind test/unionfind.cpp
tools/yosupo-test convolution_mod test/convolution_mod.cpp 10
```

問題名はURL末尾の文字列です。たとえば
`https://judge.yosupo.jp/problem/unionfind`なら`unionfind`です。
テストケースや生成物を取り直したい場合は`.yosupo/`を削除してください。
