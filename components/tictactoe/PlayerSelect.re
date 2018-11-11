open Util;
open Game;
let component = ReasonReact.statelessComponent("PlayerSelect");

let make = (~onPlayerClick, _children) => {
  ...component,
  render: _ =>
    <div>
      <span onClick={_evt => onPlayerClick(X)}> "X"->s </span>
      <span onClick={_evt => onPlayerClick(O)}> "O"->s </span>
    </div>,
};