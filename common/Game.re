type player =
  | X
  | O;

type progress =
  | Win(player)
  | Running
  | Draw;

type game = {
  currentPlayer: player,
  progress,
};

let playerToString = (p: player): string =>
  switch (p) {
  | X => "X"
  | O => "O"
  };