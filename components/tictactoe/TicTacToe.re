open Util;
open Game;

type state =
  | PlayerSelect
  | GameRunning(game)
  | Finished;

type action =
  | PlayerSelected(player);

let component = ReasonReact.reducerComponent("TicTacToe");

[@genType]
let make = _children => {
  ...component,
  initialState: () => PlayerSelect,
  reducer: (action, _state) =>
    switch (action) {
    | PlayerSelected(currentPlayer) =>
      ReasonReact.Update(GameRunning({currentPlayer, progress: Running}))
    },
  render: self => {
    let onPlayerClick = (selected: player) =>
      self.send(PlayerSelected(selected));

    switch (self.state) {
    | PlayerSelect => <PlayerSelect onPlayerClick />
    | GameRunning(gameState) =>
      let myPlayer = playerToString(gameState.currentPlayer);
      <div> {("currentPlayer: " ++ myPlayer)->s} </div>;
    | Finished => <div> "Finished"->s </div>
    };
  },
};