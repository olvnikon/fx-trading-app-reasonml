let component = ReasonReact.statelessComponent("BuyRate");

/* underscores before names indicate unused variables. We name them for clarity */
let make = (~currency: string, _children) => {
  ...component,
  render: _self => <div />,
};
