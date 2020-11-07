type t = unit => unit;

type netInfoStateType = string;

[@bs.inline]
let none = "none";

[@bs.inline]
let unknown = "unknown";

[@bs.inline]
let cellular = "cellular";

[@bs.inline]
let wifi = "wifi";

[@bs.inline]
let bluetooth = "bluetooth";

[@bs.inline]
let ethernet = "ethernet";

[@bs.inline]
let wimax = "wimax";

[@bs.inline]
let vpn = "vpn";

[@bs.inline]
let other = "other";

type netInfoCellularGeneration = string;

[@bs.inline]
let net2G = "2g";

[@bs.inline]
let net3G = "3g";

[@bs.inline]
let net4G = "4g";

type response;

[@bs.get] external status: response => int = "status";

type netInfoConfiguration;

[@bs.obj]
external netInfoConfiguration:
  (
    ~reachabilityUrl: string=?,
    ~reachabilityTest: response => bool=?,
    ~reachabilityShortTimeout: float=?,
    ~reachabilityLongTimeout: float=?,
    ~reachabilityRequestTimeout: float=?,
    unit
  ) =>
  netInfoConfiguration;

type details = {
  .
  "isConnectionExpensive": bool,
  "ssid": Js.Nullable.t(string),
  "bssid": Js.Nullable.t(string),
  "strength": Js.Nullable.t(int),
  "ipAddress": Js.Nullable.t(string),
  "subnet": Js.Nullable.t(string),
  "frequency": Js.Nullable.t(float),
  "cellularGeneration": Js.Nullable.t(netInfoCellularGeneration),
  "carrier": Js.Nullable.t(string),
};

type netInfoState = {
  .
  "_type": netInfoStateType,
  "isConnected": bool,
  "isInternetReachable": bool,
  "isWifiEnabled": bool,
  "details": Js.Null.t(details),
};

[@bs.module "@react-native-community/netinfo"]
external configure: netInfoConfiguration => unit = "configure";

[@bs.module "@react-native-community/netinfo"]
external fetch: unit => Js.Promise.t(netInfoState) = "fetch";

[@bs.module "@react-native-community/netinfo"]
external fetchInterface:
  [ | `cellular | `ethernet | `wifi] => Js.Promise.t(netInfoState) =
  "fetch";

[@bs.module "@react-native-community/netinfo"]
external addEventListener: (netInfoState => unit) => t = "addEventListener";

[@bs.module "@react-native-community/netinfo"]
external useNetInfo: unit => netInfoState = "useNetInfo";

module ConnectionType = {
  type t = string;

  [@bs.inline]
  let bluetooth = "bluetooth";

  [@bs.inline]
  let cellular = "cellular";

  [@bs.inline]
  let ethernet = "ethernet";

  [@bs.inline]
  let unknown = "unknown";

  [@bs.inline]
  let wifi = "wifi";

  [@bs.inline]
  let wimax = "wimax";
};

module EffectiveConnectionType = {
  type t = string;

  [@bs.inline]
  let net2G = "2g";

  [@bs.inline]
  let net3G = "3g";

  [@bs.inline]
  let net4G = "4g";

  [@bs.inline]
  let unknown = "unknown";
};

type info = {
  .
  "_type": ConnectionType.t,
  "effectiveType": EffectiveConnectionType.t,
};
