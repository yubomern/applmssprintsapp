import { io } from "socket.io-client";

const URL =
  import.meta.env.VITE_APP_NODE_ENV === "producton"
    ? "http://localhost:3000"
    : import.meta.env.VITE_APP_COURSIFY_API;

const socket = io(URL, {
  autoConnect: false,
});

export default socket;
