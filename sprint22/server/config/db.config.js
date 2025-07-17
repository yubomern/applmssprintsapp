import mongoose from "mongoose";

async function connectToDB() {
  try {
    const { connection } = await mongoose.connect(process.env.MONGO_URL || "mongodb://localhost:27017/lmsuser");

    if (connection) {
      console.log("connected to DB: " + connection.host);
    }
  } catch (error) {
    console.log("connection error: ", error);
    process.exit(1);
  }
}

export default connectToDB;
