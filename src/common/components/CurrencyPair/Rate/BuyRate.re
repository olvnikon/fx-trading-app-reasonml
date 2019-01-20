let component = ReasonReact.statelessComponent("BuyRate");

let make = (~currency: string, ~rate: float, _children) => {
  ...component,
  render: _self => <div> <Rate header={"Buy " ++ currency} rate /> </div>,
};
