let component = ReasonReact.statelessComponent("Triangle");

let make = (~isPositiveTrend: bool, _children) => {
  ...component,
  render: _self => <div />,
};
