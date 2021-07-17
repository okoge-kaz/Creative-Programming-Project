[問題リンク](https://atcoder.jp/contests/abc137/tasks/abc137_d)

[解説](https://img.atcoder.jp/abc137/editorial.pdf)

素直に前から金額$B_i$で貪欲法をするとWAになる。これはすぐにHackするケースを思いつける。
だがDPで解こうとしても計算量的に間に合わない。ではどうするか？

ここで考えるべきなのは優先度つきqueueを後ろから適応する。  
この解法を思いつくポイントは、1日目,2日目などは自由度が高いが、M日目など終了時点に近い後ろの方では、自由度が低いので後ろから考えるのがよいか？と思いつく

素直な貪欲法は間違えだが、大きい$B_i$を選ぶべきというのは正しい、でもいちいちsortするのは計算量を圧迫する。ここでpriority_queueを使うべき

このタイプの問題は頻出なので典型として覚えてしまうのがよい