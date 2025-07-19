const mongoose = require("mongoose");

// this in the mongoDB connection for localhost
mongoose.connect(process.env.MONGODB_URI || "mongodb://127.0.0.1:27017/elearning", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
  useCreateIndex: true,
  useFindAndModify: true,
});

// todo: use this the format for the heroku connection to MongoDB
// mongoose.connect(
//   process.env.MONGODB_URI || "mongodb://localhost:27017/googlebooks",
//   {
//     useNewUrlParser: true,
//     useUnifiedTopology: true,
//   }
// );

module.exports = mongoose.connection;
