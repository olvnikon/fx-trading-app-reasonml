let component = ReasonReact.statelessComponent("SellRate");

let make = (~currency: string, ~rate: float, _children) => {
  ...component,
  render: _self => <div> <Rate header={"Sell " ++ currency} rate /> </div>,
};
