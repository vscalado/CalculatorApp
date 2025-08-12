
resultCallback = [this](constMetaObject::invokeMethod(this, this, msg {
        onResultReceived(msg.value, QString::fromStdString(msg.status));
        logMessage("Received result: " + QString::number(msg.value) + " (" + QString::fromStdString(msg.status) + ")");
    }, Qt::QueuedConnection);
};
